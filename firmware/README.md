# Firmware for Adaptive Energy Converter

This directory contains the microcontroller firmware that implements the control logic for the op‑amp based voltage‑matching circuit.

## Target Platform
- Arduino Uno (ATmega328P) or any Arduino‑compatible board with ADC and PWM/DAC capabilities.
- Can be adapted to STM32 Blue Pill, ESP32, etc.

## Functions
- `readInputVoltage()`: reads the solar/wind input voltage via a voltage divider.
- `readBatteryVoltage()`: reads the battery voltage via a separate voltage divider.
- `calculateOptimalSetpoint()`: computes the optimal reference voltage for the op‑amp based on input and battery voltages.
- `setOpAmpReference()`: outputs the reference voltage via a DAC or PWM‑filtered analog signal.

## Building and Uploading
1. Open `firmware/src/main.cpp` in the Arduino IDE.
2. Select the correct board and port.
3. Compile and upload.

## Calibration
Adjust the scaling factors in `readInputVoltage()` and `readBatteryVoltage()` according to your actual voltage divider ratios.
