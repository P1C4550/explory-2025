#include <Arduino.h>
#include "Wire.h"
#include "TFLI2C.h"
#include "Stepper.h"

class StepperHandler
{
	private:
	int pin1, pin2, pin3, pin4;
	int steps_per_revolution;
	Stepper *stepper;
	
	public:
	StepperHandler(int p1, int p2, int p3, int p4, int steps_per_rev)
	: pin1(p1), pin2(p2), pin3(p3), pin4(p4), steps_per_revolution(steps_per_rev)
	{
		stepper = new Stepper(steps_per_rev, p1, p2, p3, p4);
	}
	
	// Destructor to free memory
	~StepperHandler()
	{
		delete stepper;
	}
	
	void stepAtSpeed(int steps, int speed)
	{
		stepper->setSpeed(speed);
		stepper->step(steps);
		off();
	}
	
	void off()
	{
		digitalWrite(pin1, LOW);
		digitalWrite(pin2, LOW);
		digitalWrite(pin3, LOW);
		digitalWrite(pin4, LOW);
	}
};

// 25, 26 pins

TFLI2C tflI2C;

#define STEPS_PER_REVOLUTION 200

StepperHandler stepper(25, 26, 27, 13, STEPS_PER_REVOLUTION);

void setup()
{
	Serial.begin(115200);
	Wire.begin();

	for (int i = 1; i < 15; i+=1) {
		stepper.stepAtSpeed(i*10, i);
	}
}

void loop()
{
	// delay(50);
	// int16_t dist;
	// if (tflI2C.getData(dist, 0x10)) {
	// 	Serial.print("dist:");
	// 	Serial.println(dist);
	// }
	delay(1000);
}
