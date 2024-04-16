```
Story:

using arduino c++ code write a programme to output every second in a csv format 
a line that contains the sensor data for an Arduino Uno has the following sensors 
attached: DHT11, Soil Moisture Meter, DS1302 RTC sensor, Light Sensor (LDR Photoresistor)
and has a MicroSD card reader attached with the following pinouts. 

#################################### //
PINOUT: DHT11
#################################### //
VCC    --> 5V 
GND     --> GND
DATA    --> D4
#################################### //
PINOUT: SOIL METER
#################################### //
VCC    --> 5V 
GND     --> GND
DATA    --> A2
#################################### //
PINOUT: LDR (PHOTOSENSOR)
#################################### //
VCC    --> 5V 
GND     --> 270ohm RES
RES    --> A1
#################################### //
PINOUT: MICRO SD card reader
#################################### //
VCC    --> 5V 
GND     --> GND
MISO --> D12
MOSO --> D11
SCK     --> D13
CS     --> D10
#################################### //
PINOUT: DS1302 RTC
#################################### //
CS    --> D5  // Chip Enable
DATA  --> D6  // Input/Output
SCK   --> D7  // Serial Clock
VCC   --> 5V 
GND   --> GND
#################################### //
PINOUT: LED Confirm MicroSD Write
#################################### //
LED --> D8
LED --> 270 ohm RES
RES --> GND
#################################### //
PINOUT: LoRa
#################################### //
ATK-LORA-01 V30 
SX1278
410MHZ-411MHZ 
DC3.3V-5V module
------------------------------------ //
Search: "OSOYOO UART LoRa wireless module"
Source: https://osoyoo.com/2018/07/26/osoyoo-lora-tutorial-how-to-use-the-uart-lora-module-with-arduino/
------------------------------------ //
VCC   --> 5V 
GND   --> GND
M0    --> GND  #--- sets default mode TX/RX
TX    --> 2    #--- GPIO(any)
RX    --> 3    #--- GPIO(any)
AUX   --> NC   #--- not connected
#################################### //
boost converter (STANDALONE POWER)
#################################### //
5*DC-DC Boost Converter Step Up Module 
1-5V to 5V 600mA
Input voltage: 1V~5V
Output: 5V / 500mA
PCB size: 17.55mm*25.22mm*5.85 mm
#################################### //
Charger TP4056 (STANDALONE POWER)
#################################### //
TP4056 Standalone Linear Li-lon Battery Charger with Thermal Regulation in SOP-8
https://dlnmh9ip6v2uc.cloudfront.net/datasheets/Prototyping/TP4056.pdf
·Input Supply Voltage(VCC)：-0.3V～8V
·TEMP：-0.3V～10V
·CE：-0.3V～10V
·BAT Short-Circuit Duration：Continuous
·BAT Pin Current：1200mA
·PROG Pin Current：1200uA
·Maximum Junction Temperature：145℃
·Operating Ambient Temperature Range：-40
℃～85℃
·Lead Temp.(Soldering, 10sec)：260℃
https://dlnmh9ip6v2uc.cloudfront.net/datasheets/Prototyping/TP4056.pdf

#################################### //
Standalone Power Supply
#################################### //
USE: standalone 18650 power + USB TypeC Charger
·boost converter (BCONV)
·Battery Charger (BCHRG)
·18650           
·Arduino
-----------------------------------------------------
TP4056       | BoostConverter  | 18650    | Arduino        
-----------------------------------------------------
OUT(+)  -->  | IN(+)           |          |
OUT(-)  -->  | IN(-)           |          |
B(+)    -----|-----------------|-> (+)    |
B(-)    -----|-----------------|-> (-)    |
             | VCC  ----------------------|-> VIN
             | 5V   ----------------------|-> GND
#################################### //


```
