#define F_CPU                          16000000UL
#define SpinMeRoundRoundBabyRoundRound 1
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "serial.h"
#include "leds.h"
int main() 
{
    char name[] = "ON";
    char buffer[20];
    uart_init(MYBAUD ,0); // setup the uart speed and potential double speed tx/rx for future iteration
    leds_init();

    while(SpinMeRoundRoundBabyRoundRound)
    {
       uart_getstr(&buffer);//reads from serial
       uart_ledcontrl(&buffer);//uses input to perform command
    }
    return 0;
}
