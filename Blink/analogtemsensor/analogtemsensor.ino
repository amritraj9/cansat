#include <math.h>
int sensorPin = A1; // Declaration of the input pin
// These function translates the recorded analog measurement
double Thermistor(int RawADC)
{
 double Temp;
 Temp = log(10000.0 * ((1024.0 / RawADC - 1)));
 Temp = 1 /(0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
 Temp = Temp - 273.15; // convert from Kelvin to Celsius
 return Temp;
}
// Serial output in 9600 Baud

void setup()
{
 Serial.begin(9600);
}
// The program measures the current voltage value on the NTC
// and translates it intp °C for the serial output
void loop()
{
/// int readVal = ;
 //double temp = Thermistor(analogRead(sensorPin));
 // Output on the serial interface
 ///Serial.print("Current temperature is:");
 Serial.print(Thermistor(analogRead(A1)));
 Serial.println(" c");
 
 delay(1000);
}
