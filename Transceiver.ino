#include <SPI.h>
#include <RF24.h>
//TODO Sende analoge daten für joystick
RF24 radio(9, 10); // (CE, CSN)
const byte address[6] = "1RF24";
struct dataStruct {
    int X1;
    int Y1;
	int X2;
	int Y2;

} myData;

void setup() {
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(50);
  radio.openWritingPipe(address);
  radio.stopListening();
  Serial.begin(9600);

}

void loop() {
  //  Serial.println(radio.isChipConnected());

  myData.X1 = analogRead(0);
  myData.Y1 = analogRead(1);
  myData.X2 = analogRead(2);
  myData.Y2 = analogRead(3);
  radio.write(&myData, sizeof(myData), 1);
  delay(10);
}
