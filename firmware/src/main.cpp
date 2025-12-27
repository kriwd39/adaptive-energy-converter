#include "../include/voltage_matching.h"

// Pin definitions
#define PIN_INPUT_VOLTAGE A0
#define PIN_BATTERY_VOLTAGE A1
#define PIN_OPAMP_REF A2 // DAC or PWM output

void setup() {
  Serial.begin(9600);
  pinMode(PIN_INPUT_VOLTAGE, INPUT);
  pinMode(PIN_BATTERY_VOLTAGE, INPUT);
  pinMode(PIN_OPAMP_REF, OUTPUT);
  // Initialize DAC or PWM
  analogWriteResolution(12); // if supported
}

void loop() {
  float inputVoltage = readInputVoltage();
  float batteryVoltage = readBatteryVoltage();
  float optimalSetpoint = calculateOptimalSetpoint(inputVoltage, batteryVoltage);
  setOpAmpReference(optimalSetpoint);
  
  Serial.print("Input: "); Serial.print(inputVoltage); Serial.print(" V | ");
  Serial.print("Battery: "); Serial.print(batteryVoltage); Serial.print(" V | ");
  Serial.print("Setpoint: "); Serial.print(optimalSetpoint); Serial.println(" V");
  
  delay(1000); // adjust every second
}

float readInputVoltage() {
  // Read ADC and convert to voltage (assuming voltage divider scaling)
  int adcValue = analogRead(PIN_INPUT_VOLTAGE);
  return (adcValue / 1023.0) * 5.0 * 3.0; // example scaling for 0-15V input
}

float readBatteryVoltage() {
  int adcValue = analogRead(PIN_BATTERY_VOLTAGE);
  return (adcValue / 1023.0) * 5.0 * 6.0; // example scaling for 0-30V battery
}

float calculateOptimalSetpoint(float inputVoltage, float batteryVoltage) {
  // Simple algorithm: if input voltage is lower than battery, boost to battery voltage
  // with a small margin to account for losses
  const float margin = 0.5; // volts
  if (inputVoltage < batteryVoltage) {
    return batteryVoltage + margin;
  } else {
    // Input higher than battery: we can't step down with this topology,
    // so limit to battery voltage (or implement buck capability)
    return batteryVoltage;
  }
}

void setOpAmpReference(float voltage) {
  // Convert voltage to DAC value (0-3.3V output range)
  // Assuming 12-bit DAC, 3.3V full scale
  int dacValue = (voltage / 3.3) * 4095;
  analogWrite(PIN_OPAMP_REF, dacValue);
}
