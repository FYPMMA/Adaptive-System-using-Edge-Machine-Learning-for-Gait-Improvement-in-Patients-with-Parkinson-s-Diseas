# Gait Improvement Adaptive System for Parkinson's Disease

This repository contains the code and documentation for a Gait Improvement Adaptive System for Parkinson's Disease. This system utilizes IMU data, specifically accelerometer and gyroscope data, to address gait irregularities in patients with Parkinson's Disease.

## Table of Contents

1. [Introduction](#introduction)
2. [Methodology](#methodology)
   - [Data Collection](#data-collection)
   - [ERC Approval](#erc-approval)
   - [Data Preprocessing](#data-preprocessing)
   - [Model Training and Evaluation](#model-training-and-evaluation)
   - [Model Size Optimization](#model-size-optimization)
   - [Edge Device Integration](#edge-device-integration)
   - [Cue Prediction and Delivery](#cue-prediction-and-delivery)
   - [Monitoring System](#monitoring-system)
3. [Usage](#usage)
4. [Installation](#installation)
5. [Contributing](#contributing)
6. [License](#license)

## Introduction

Parkinson's Disease (PD) affects gait patterns, causing mobility issues for patients. This adaptive system aims to provide real-time feedback and tailored cues to improve gait for individuals with PD. It utilizes IMU sensors and machine learning models for predictive analysis.

## Methodology

### Data Collection

The data collection process involves acquiring accelerometer and gyroscope data from the ankles of patients at Parkinson Clinic, THK. Due to limited availability of patients, a data augmentation technique was applied to mimic walking patterns, which were then labeled according to the corresponding walking stage.

### ERC Approval

A FERCSL approval was obtained from ERC, Faculty of Medicine, University of Ruhuna, to collect Gait data using IMU sensors from PD patients. The approval process involved detailed documentation and certificates of training for investigators.

### Data Preprocessing

Collected data undergoes trimming tasks to enhance its quality and accuracy. Time series segmentation is applied to establish sensible data sample sizes. A diverse dataset is ensured through effective shuffling.

### Model Training and Evaluation

Various machine learning models are employed, including SVM, ANN, CNN, Decision Trees, Random Forest, RNN, and LSTM. Models are evaluated based on accuracy, precision, recall, and F1 Score. The best-performing models undergo further hyperparameter fine-tuning.

### Model Size Optimization

Deep learning models are optimized to fit within 1 MB of memory size. Techniques such as quantization are applied to reduce memory and computation requirements.

### Edge Device Integration

Trained machine learning models are integrated into embedded systems using TensorFlow Lite. Optimization for speed and efficiency ensures real-time processing capability.

### Cue Prediction and Delivery

The model predicts the PD stage, triggering specific cues via the microcontroller. Hardware components are set up to deliver auditory, visual, and tactile cues based on the model's outputs.

### Monitoring System

A comprehensive monitoring system is developed to provide real-time insights into gait patterns and patient records. It supports real-time feedback, patient safety, long-term assessment, customization, and research and development efforts.

## Usage

[Provide instructions on how to use the system or integrate it into an application.]

## Installation

[Include installation instructions for any specific software or libraries required to run the system.]

## Contributing

[Explain how others can contribute to this project. Include guidelines for pull requests, reporting issues, etc.]

## License

[Specify the license under which this project is distributed.]
