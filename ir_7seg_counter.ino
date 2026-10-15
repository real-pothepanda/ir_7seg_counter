#include "decoder.h"
const int OUT = 34; // Diin nakasaksak ang IR sensor, bantayi kay basi ma-short

int Number_of_Objects = 0;
int lastSensorState = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(OUT, INPUT);
  setupDecoder();
  
  // Gina-check namon daan ang sensor pag-on pa lang para indi mag-trip kag mag-jump sa 1 dayon
  lastSensorState = digitalRead(OUT); 
}

void loop() {
  int sensorState = digitalRead(OUT); // Basahon ta kon may nag-agi nga milagro (o tawo)
  if (sensorState == HIGH && lastSensorState == LOW) {  // Kon may nag-agi, saka ta dayon ang counter
    Number_of_Objects++;
    
    if (Number_of_Objects > 99) { // Kung mag-abot na 100, balik sa zero kay 2 digits lang ta bi
      Number_of_Objects = 0;      // Tadaaa! Back to zero
    }
    
    Serial.print("Object Count: ");
    Serial.println(Number_of_Objects);
  }
  
  lastSensorState = sensorState;
  displayTwoDigits(Number_of_Objects); // Tawgon ang decoder para magpakita sang numero
  delay(50); // Pahuway gamay kay basi gikapoy na ang ESP32
}