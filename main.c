#define LED_BluePIN     1
#define LED_GreenPIN    2
#define LED_RedPIN      3
#define BUTT1 0
#define BUTT2 4
#define F_CPU           16000000UL

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"


void ledBlueBlink()
{
     PORTB ^= (1 << LED_BluePIN);
     //_delay_ms(2000);
}
void ledGreenBlink()
{
     PORTB &= ~(1 << LED_BluePIN);
     PORTB &= ~(1 << LED_RedPIN);
     PORTB ^= (1 << LED_GreenPIN);
     //_delay_ms(2000);
}
void ledRedBlink()
{
     PORTB ^= (1 << LED_RedPIN);
     //_delay_ms(2000);
}


int main() 
{
    int state = 1;
    char name[] = "Vincent Palma\r\n";
    uart_init(MYBAUD ,0);
    //DDRB |=(1<< LED_BluePIN); 
    //DDRB |=(1<< LED_GreenPIN);
    DDRB |=(1<< LED_RedPIN);

    while(1)
    {
        switch (state)
        {
        case 1:
            ledRedBlink();
            break;
        case 2:
            ledGreenBlink();
            break;
        case 3:
            ledBlueBlink();
            break;
        
        default:
            state = 1;
            break;
        }
       
       //uart_txchr('K');
       _delay_ms(500);
       uart_putstr(name);

    }
    return 0;
}
