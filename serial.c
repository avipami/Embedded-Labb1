#include <avr/io.h>
#include <avr/interrupt.h>
#include "serial.h"
#include "leds.h"

void uart_init(unsigned int baud, int highSpeed)
{
    uint8_t speed = 16;
    if (highSpeed != 0)
    {
        speed = 8;
        UCSR0A |= 1 << U2X0; /* Enables high speed */
    }
    UBRR0L = (uint8_t)(baud & 0x00FF);
    UBRR0H = (uint8_t)(baud  >> 8);
    
       /* Baud Reg set */

    UCSR0B = (1<<RXEN0)|(1<<TXEN0);     /* Enable receiver and transmitter */ 
    UCSR0C = (1<<USBS0)|(3<<UCSZ00);    /* Set frame format: 8data, 2stop bit Async mode on*/ 
}

void uart_putchar(unsigned char chr)
{
    /* Wait for empty transmit buffer */
    while ((UCSR0A & (1<<UDRE0))== 0);
    UDR0 = chr; // print to serial screen
}

void printNewLine()// this function gives a new line on serial monitor
{
    while ((UCSR0A & (1<<UDRE0))== 0);
    UDR0 = '\r';
    while ((UCSR0A & (1<<UDRE0))== 0);
    UDR0 = '\n';
}

char uart_getchar(void)
{
 while (!(UCSR0A & (1<<RXC0))); 
 // If not UCSRnA register port RXCn is 1 when and:ing (1<<RXCn) wait.

/* Get and return received data from buffer */
  
return UDR0;
}
void uart_getstr(char *buffer)
{
    int i = 0;

    buffer[i] = uart_getchar();
    uart_putchar(buffer[i]);
    while ((buffer[i] != '\r') & (buffer[i] != '\n')) // while there is no return key pressed go through the input
    {
        if (i <= 20) {
            i++;
            buffer[i] = uart_getchar();
        } else {
            buffer[i] = uart_getchar();
        }
        uart_putchar(buffer[i]);
    }
    buffer[i] = '\r'; // insert a return to start of array
    i++;
    buffer[i] = '\n'; // insert a new line to array
    buffer[i + 1] = '\0';
}
void uart_echo(void) //not necessary in this iteration
{
    uart_putchar(uart_getchar());   
}