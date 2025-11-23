#include <Arduino.h>
#include "Wire.h"
#include "TFLI2C.h"

TFLI2C tflI2C;

void setup() {
	Serial.begin(115200);
	Wire.begin();
}

void loop() {
	delay(50);
	int16_t dist; 
	if (tflI2C.getData(dist, 0x10)) {
		Serial.print("dist:");
		Serial.println(dist);
  	}
}
