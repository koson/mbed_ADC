/*
 * rosserial ADC Example
 *
 * This is a poor man's Oscilloscope.  It does not have the sampling
 * rate or accuracy of a commerical scope, but it is great to get
 * an analog value into ROS in a pinch.
 */

#include "mbed.h"
//#include <rosserial_mbed/Adc.h>

#if defined(TARGET_LPC1768)
PinName adc0 = P1_31;
PinName adc1 = p16;
PinName adc2 = p17;
PinName adc3 = p18;
PinName adc4 = p19;
PinName adc5 = p20;
#elif defined(TARGET_KL25Z) || defined(TARGET_NUCLEO_F401RE)
PinName adc0 = A0;
PinName adc1 = A1;
PinName adc2 = A2;
PinName adc3 = A3;
PinName adc4 = A4;
PinName adc5 = A5;
#else
#error "You need to specify the pins for the adcs"
#endif

Serial serial(P0_2, P0_3); //RxD, TxD usb

int adc0Val;


//We average the analog reading to elminate some of the noise
int averageAnalog(PinName pin) {
    int v=0;
    for (int i=0; i<4; i++) v+= AnalogIn(pin).read_u16();
    return v/4;
}

long adc_timer;

int main() {
	serial.baud(19200);
	serial.printf("Ready\r\n");

    while (1) {
        adc0Val = averageAnalog(adc0);
		serial.printf("%d\r\n",adc0Val);

    }
}
