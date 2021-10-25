#define LED_PIN 1
#define F_CPU 16000000UL

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"


void ledBlink()
{
     PORTB ^= (1 << LED_PIN);
     //_delay_ms(2000);
}


int main() 
{
    uart_init(MYBAUD ,0);
    DDRB |=(1<< LED_PIN); 
    while(1)
    {
       ledBlink();
       uart_tx('K');
       _delay_ms(500);

    }
    return 0;
}
