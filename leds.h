#ifndef LEDS_H
#define LEDS_H

#define LED_BluePIN     1
#define LED_GreenPIN    2
#define LED_RedPIN      3
#define BUTT1 0
#define BUTT2 4

void leds_init();

void ledBlueBlink();
void ledGreenBlink();
void ledRedBlink();
void ledPurpleBlink();
void uart_ledcontrl(char *str);


#endif