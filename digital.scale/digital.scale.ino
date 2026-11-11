#include "HX711.h"


const int LOADCELL_DOUT_PIN = 12; 
const int LOADCELL_SCK_PIN = 14;  

HX711 scale;

void setup() {
  Serial.begin(115200);

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  scale.set_scale(1.f); 
  
  scale.tare(); 
  
}

void loop() {
  Serial.println(scale.get_units(10), 2); 
  
  if (Serial.available()) {
    char temp = Serial.read();
    if (temp == 't' || temp == 'T') {
      scale.tare();
    }
  }

  delay(1000);
}