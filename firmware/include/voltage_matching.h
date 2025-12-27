#ifndef VOLTAGE_MATCHING_H
#define VOLTAGE_MATCHING_H

float readInputVoltage();
float readBatteryVoltage();
float calculateOptimalSetpoint(float inputVoltage, float batteryVoltage);
void setOpAmpReference(float voltage);

#endif // VOLTAGE_MATCHING_H
