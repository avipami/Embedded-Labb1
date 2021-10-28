#include <util/delay.h>
#include <avr/io.h>
#include <string.h>
#include "leds.h"
#include "serial.h"

void leds_init()    // Function to initialize the leds and put them in a off state
{
    DDRB |= (1<< LED_BluePIN); 
    DDRB |= (1<< LED_GreenPIN);
    DDRB |= (1<< LED_RedPIN);  
    PORTB |= (1 << LED_BluePIN);
    PORTB |= (1 << LED_RedPIN);
    PORTB |= (1 << LED_GreenPIN);
}

void ledBlueBlink() // A blue blink blink function
{
     PORTB ^= (1 << LED_BluePIN);
     PORTB |= (1 << LED_GreenPIN);
     PORTB |= (1 << LED_RedPIN);
}

void ledGreenBlink() // A green blink blink function
{
     PORTB |= (1 << LED_BluePIN);
     PORTB |= (1 << LED_RedPIN);
     PORTB ^= (1 << LED_GreenPIN);
     _delay_ms(2000);
}

void ledRedBlink() // A red blink blink function
{
     PORTB ^= (1 << LED_RedPIN);
     PORTB |= (1 << LED_GreenPIN);
     PORTB |= (1 << LED_BluePIN);
     _delay_ms(2000);
}

void ledPurpleBlink() // A purple blink blink function
{
     PORTB ^= (1 << LED_RedPIN);
     PORTB |= (1 << LED_GreenPIN);
     PORTB ^= (1 << LED_BluePIN);
     _delay_ms(2000);
}

void togglePurple() // A purple color set/unset function
{
     PORTB ^= (1 << LED_RedPIN);
     PORTB |= (1 << LED_GreenPIN);
     PORTB ^= (1 << LED_BluePIN);
}
void turnOffBlueLed()
{
    PORTB |=(1<< LED_BluePIN); 
}
void turnOnBlueLed()
{
    PORTB &= ~(1<< LED_BluePIN); 
}

void uart_ledcontrl(char *str) //Control leds (blue) depending on uart command
{
    if(!strcmp(str,"ON\r\n"))
    {
        turnOnBlueLed();
    }
    if(!strcmp(str,"OFF\r\n"))
    {
        turnOffBlueLed();
    }
    if (!strcmp(str,"PURPLE\r\n"))
    {
        togglePurple();
    }
    

    printNewLine();  
}
