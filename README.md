# Soil Moisture Monitoring and Automatic Watering System


## Hardware Requirements

- Arduino UNO or compatible board
- Soil moisture sensor
- Pump
- LCD Display

## Connections

1. Connect the sensor to pin A0.
2. Connect the pump to pin 6.
3. Connect the LCD's SDA and SCL to Arduino's A4 and A5 pins respectively.

## Operating Instructions

The system functions as follows:

- Continuously monitors the moisture content of the soil through the sensor.

  - :) Nice! - when moisture is above 70%
  - :O    oh. - when moisture is between 40% and 70%
  - :( I am sad. - when moisture is below 40% and also triggers pump
  
The moisture levels are also outputted over the serial interface for potential remote monitoring.
