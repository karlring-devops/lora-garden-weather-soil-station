/*
  Description:  ATK-LORA-01 V3 410MHZ-411MHZ SX1278
  References:   https://www.aliexpress.us/item/3256804436232804.html?gatewayAdapt=glo2usa4itemAdapt
                https://osoyoo.com/2018/07/26/osoyoo-lora-tutorial-how-to-use-the-uart-lora-module-with-arduino/
  Chipset:      SX1278
  Notes:        ATK-LORA-01 LORA module wireless serial communication module SX1278 wireless module 3000 meters
  Power:        3.3v-5v
  Pinout:       SX1278                            |Arduino Micro
                ----------------------------------|------------------------------------------
                MD0: Mode select pin 0            | GPIO (x)
                AUX: Auxiliary pin                | GPIO/INT
                TXD: Transmit data pin            | RXD
                RXD: Receive data pin             | TXD
                GND: Ground                       | GND
                VCC: Power supply (3.3V - 5V)     | 5V
*/
/*
  Description:  [ST7735R] 1.8" 128x160 TFT LCD with SPI Interface
  References:   [master source/code/wire] 
                https://randomnerdtutorials.com/guide-to-1-8-tft-display-with-arduino/ 
                [others]
                https://learn.adafruit.com/1-8-tft-display/breakout-wiring-and-test
                https://focuslcds.com/wp-content/uploads/Specs/E17RG11216LW6M300-R_Spec.pdf
                https://www.hotmcu.com/18-128x160-tft-lcd-with-spi-interface-p-314.html
                
  Chipset:      ST7735R
  Notes:        WORKS on Nano with [randomnerds]
  Power:        3.3v-5v
  Pinout:       1.8 TFT - ST7735R                 |Arduino Uno/Nano
                ----------------------------------|------------------------------------------
                LED:	                            | 3.3 V
                SCK:	                            | 13  (GPIO)
                SDA:	                            | 11  (GPIO)
                A0 :                              | 9   (GPIO)
                RST:                              | 8   (GPIO)
                CS :                              | 10  (GPIO)
                GND:	                            | GND (GPIO)
                VCC:	                            | 5 V 

                MicroSD - 1.8 TFT - ST7735R       | Arduino Uno/Nano
                -----------------------------------------------------------------------------
                CS  :	                            | 4  (GPIO)
                MOSI:	                            | 11 (GPIO)  
                MISO:	                            | 12 (GPIO)
                SCK	:                             | 13 (GPIO)
*/

// #######################################
// RECEIVER
// #######################################

// #########################################################
// https://osoyoo.com/2018/07/26/osoyoo-lora-tutorial-how-to-use-the-uart-lora-module-with-arduino/
// #########################################################
// WINNER!!! this one works both ways on Micro + Nano boots
// #########################################################

//------------------------------------------------------------------

// [ST7735R] include TFT and SPI libraries
#include <TFT.h>  
#include <SPI.h>
// [ST7735R] pin definition for Arduino UNO
#define ST7735R_CS   10
#define ST7735R_DC   9
#define ST7735R_RST  8
// [ST7735R] create an instance of the library
TFT TFTscreen = TFT(ST7735R_CS, ST7735R_DC, ST7735R_RST);

//------------------------------------------------------------------

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //TX, RX
// (Send and Receive)

void resetDisplay(){
  //[ST7735R] clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  //[ST7735R] set the text size
  TFTscreen.setTextSize(2);
}

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  //------------------------------------------------------------------
  //[ST7735R] initialize the library
  TFTscreen.begin();
  // //[ST7735R] clear the screen with a black background
  // TFTscreen.background(0, 0, 0);
  // //[ST7735R] set the text size
  // TFTscreen.setTextSize(2);
  resetDisplay();
  //------------------------------------------------------------------
}

void loop() {

  if(Serial.available() > 0){
    //Read from serial monitor and send over 
    // OSOYOO UART LoRa wireless module
    String input = Serial.readString();
    mySerial.println(input);    
    Serial.println("[SND] " + input);  
  }
 
  if(mySerial.available() > 1){
    //Read from  OSOYOO UART LoRa wireless module 
    // and send to serial monitor
    String input = mySerial.readString();
    String message = String("[RCV] " + input);
    Serial.println(message); 
    //------------------------------------------------------------------
    // [ST7735R] generate a random color
    int redRandom = random(0, 255);
    int greenRandom = random (0, 255);
    int blueRandom = random (0, 255);
    // [ST7735R] set a random font color
    TFTscreen.stroke(redRandom, greenRandom, blueRandom);
    // print Hello, World! in the middle of the screen
    TFTscreen.text("[RCV] ok!", 6, 57);
    // TFTscreen.text("Hello, World!", 6, 57);
    delay(6);
    //------------------------------------------------------------------
  }
    resetDisplay();

}
