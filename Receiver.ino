#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
Servo sg0; Servo sg1; Servo sg2; Servo sg3; RF24 radio(9, 8); /* CE, CSN */ const byte address[5] = {0xAB, 0xCD, 0xEF, 0x01, 0x23}; void setup() {
Serial.begin(9600); radio.begin(); radio.openReadingPipe(0, address); radio.setPALevel(RF24_PA_MIN); radio.setDataRate(RF24_250KBPS); radio.startListening();
radio.powerUp(); sg0.attach(3); sg1.attach(5); sg2.attach(6); sg3.attach(10); } void loop() { if (radio.available()) {
int text[3];/* Print only 32 characters so 32 bayt */ radio.read(&text, sizeof(text)); Serial.print(text[0]); Serial.print("    ");
Serial.print(text[1]); Serial.print("    "); Serial.println(text[2]); text[0] = map(text[0], 0, 1023, 0, 179); text[1] = map(text[1], 0, 1023, 0, 179);
text[2] = map(text[2], 0, 1023, 0, 90); sg0.write(text[0]); sg1.write(text[1]); sg2.write(text[2]); sg3.write(text[2]); } }
