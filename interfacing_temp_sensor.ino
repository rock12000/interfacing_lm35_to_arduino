#include <TimerOne.h>
const int lm35_pin = A0;	/* LM35 O/P pin */
int LEDpin = 10;  /* Later we are using Timer1 library which is applicable only to pins numbered 9 and 10 , so LED is connected to either pin 9 or pin 10 */


// Generally, we should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store

 
void setup() {
  pinMode(LEDpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);	/* Read Temperature using the pin */
  temp_val = (temp_adc_val * 4.88);	/* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10);	/* LM35 gives output of 10mv/°C . This value is in celcius*/
 
  if(temp_val < 30)
	{
	digitalWrite(10, HIGH);
	Timer1.setPeriod(250000);    /* Timer is initialized,  time is in microseconds, 250ms = 250 x 1000 = 250000 us */
  	Timer1.attachInterrupt(digitalWrite(10, !digitalRead(10)));
	}


if(temp_val > 30)
	{
	digitalWrite(10, HIGH);
	Timer1.setPeriod(500000);    /* Timer is initialized,  time is in microseconds, 500ms = 500 x 1000 = 500000 us */
  	Timer1.attachInterrupt(digitalWrite(10, !digitalRead(10)));
		
}


}