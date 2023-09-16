#include <ArduinoBLE.h>
#include <Arduino_LSM9DS1.h>

#define CONVERT_G_TO_MS2    9.80665f
#define FREQUENCY_HZ        119
#define INTERVAL_MS         (1000 / (FREQUENCY_HZ+1))

float accX, accY, accZ;
float gyroX, gyroY, gyroZ;
unsigned long last_interval_ms = 0;
unsigned long startTime;
unsigned long packetTime;
const String del = ";";
const int strLen = 10 +6*3*5+5*3*5;
String sampleData;

unsigned int sampleCounter = 0;  // Counter for the number of samples
unsigned int samplePacket = 0; 

BLEService sensorService("50ffdae7-f761-4bbf-bfdc-4d3d65e5b774");
BLEStringCharacteristic sensorCharacteristic("50ffdae7-f761-4bbf-bfdc-4d3d65e5b774", BLERead | BLENotify, strLen);

void setup() {
  IMU.begin();
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  if (!BLE.begin()) {
    Serial.println("BLE failed to Initiate");
    delay(500);
    while (1);
  }

  BLE.setLocalName("Arduino Sensor Data");
  BLE.setAdvertisedService(sensorService);
  sensorService.addCharacteristic(sensorCharacteristic);
  BLE.addService(sensorService);
  sensorCharacteristic.writeValue("1111111111;-0.00;-0.00;-0.00;0.00;0.00;0.00;-0.00;-0.00;-0.00;0.00;0.00;0.00;-0.00;-0.00;-0.00;0.00;0.00;0.00;-0.00;-0.00;-0.00;0.00;0.00;0.00;-0.00;-0.00;-0.00;0.00;0.00;0.00;");
  BLE.advertise();

  Serial.println("Bluetooth device is now active, waiting for connections...");
}

void loop() {
  BLEDevice central = BLE.central();
  if (central) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());
    digitalWrite(LED_BUILTIN, HIGH);
    while (central.connected()) {
      if (sampleCounter==0){
         startTime = millis();
         delay(2000); 
         }
      
      while(sampleCounter<500000 && millis() > last_interval_ms + INTERVAL_MS) {
        readSensors();
        last_interval_ms = millis(); 
        sampleCounter++;
        samplePacket++;
      
        if(samplePacket>4){
          packetTime = millis();
          String msg = get_message();
          sensorCharacteristic.writeValue(msg);
          printToSerial();
          samplePacket = 0;
          sampleData = "";      
      }
    }
  }
  }
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println(central.address());
  sampleCounter=0;
}

void readSensors() {
  if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {
    IMU.readAcceleration(accX, accY, accZ);
    IMU.readGyroscope(gyroX, gyroY, gyroZ);
    

    accX *= CONVERT_G_TO_MS2;
    accY *= CONVERT_G_TO_MS2;
    accZ *= CONVERT_G_TO_MS2;
    gyroX *= CONVERT_G_TO_MS2;
    gyroY *= CONVERT_G_TO_MS2;
    gyroZ *= CONVERT_G_TO_MS2;
    
    sampleData += getSensorDataMessage();
  }
}

void printToSerial() {
  Serial.print(sampleCounter); Serial.print('\t');
  Serial.print(sampleData); Serial.print('\n'); 
}

String getSensorDataMessage() {
  return String(accX) + del + String(accY) + del + String(accZ) +
         del + String(gyroX) + del + String(gyroY) + del + String(gyroZ)+del;
}

String get_message() {
  return String(sampleCounter)+ del +String(sampleData); 
}
