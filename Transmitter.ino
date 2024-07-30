#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 8);
const byte address[5] = {0xAB, 0xCD, 0xEF, 0x01, 0x23}; 
void setup() { 
  radio.begin(); 
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX); 
  radio.setDataRate(RF24_250KBPS); 
  radio.stopListening(); 
  radio.powerUp(); 
  pinMode(A0,INPUT); 
  pinMode(A1,INPUT); 
  pinMode(A2,INPUT); 
} 
void loop() { 
  int text[3]; 
  text[0] = analogRead(A0); 
  text[1] = analogRead(A1); 
  text[2] = analogRead(A2); 
  radio.write(&text, sizeof(text)); 
}
