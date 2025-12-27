# Adaptive Energy Converter

An op-amp-based voltage-matching circuit for solar/wind energy conversion to higher voltage batteries.

## Overview

This project implements a novel op-amp-based voltage-matching circuit that adjusts the output voltage of a solar panel or wind turbine to match the voltage of a higher-voltage battery. The circuit optimizes power output by continuously matching the input voltage to the battery voltage, enabling efficient energy harvesting across a wide range of input voltage levels.

## Problem Statement

Renewable energy sources like solar panels and wind turbines produce variable DC voltages depending on environmental conditions. To store this energy in a battery bank, the input voltage must be boosted and regulated to match the battery's voltage. Traditional boost converters often operate at fixed duty cycles, leading to suboptimal power transfer when the input voltage varies. This circuit solves that problem by dynamically adjusting the output voltage to track the battery voltage, ensuring maximum power point tracking (MPPT) like behavior.

## System Block Diagram

```
┌─────────────────┐      ┌──────────────────────┐      ┌──────────────┐
│ Solar/Wind      │      │ Adaptive Energy      │      │ High Voltage │
│ Source          │─────▶│ Converter            │─────▶│ Battery      │
│ (Variable DC)   │      │ (Op‑amp Controller)  │      │ (Fixed DC)   │
└─────────────────┘      └──────────────────────┘      └──────────────┘
```

## Features

- **Wide Input Voltage Range:** Can accept inputs from 5 V to 30 V DC.
- **Op‑amp Based Control:** Uses an operational amplifier in a feedback loop to precisely set the output voltage.
- **Microcontroller Interface:** Firmware reads battery voltage and calculates the optimal set‑point for the op‑amp reference.
- **Efficiency Optimized:** Minimizes switching losses by operating the boost converter near its optimal duty cycle.
- **Open‑Source Hardware & Software:** Full schematic, bill of materials, firmware, and simulation files are provided.

## Status

🚧 **Project is currently in development.**  
The initial design and documentation are being actively worked on. Refer to the [Issues](https://github.com/kriwd39/adaptive-energy-converter/issues) tab for the current task list.

## Getting Started

Once the development is complete, this section will link to the assembly guide, firmware installation instructions, and simulation examples.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.