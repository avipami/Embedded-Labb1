#include <avr/io.h>
#include <avr/interrupt.h>
#include "serial.h"

void uart_init(unsigned int baud, int highSpeed)
{
    uint8_t speed = 16;
    if (highSpeed != 0)
    {
        speed = 8;
        UCSR0A |= 1 << U2X0; /* Enables high speed */
    }

    //baud = (F_CPU/(speed*baud)) -1;

    UBRR0L = (uint8_t)(baud & 0x00FF);
    UBRR0H = (uint8_t)(baud  >> 8);
    
       /* Baud Reg set */

    UCSR0B = (1<<RXEN0)|(1<<TXEN0);     /* Enable receiver and transmitter */ 
    UCSR0C = (1<<USBS0)|(3<<UCSZ00);    /* Set frame format: 8data, 2stop bit Async mode on*/ 
}

void uart_txchr(unsigned char chr)
{
    /* Wait for empty transmit buffer */
    while ((UCSR0A & (1<<UDRE0))==0);
    /* Put data into buffer, sends the data */ 
    UDR0 = chr;
}
void uart_putstr(const char *str)
{
    while (*str > 0)
    {
        uart_txchr(*str++);
    }
    
}

char uart_getchar(void)
{
 while ( !(UCSR0A & (1<<RXC0))); // If not UCSRnA register port RXCn is 1 when and:ing (1<<RXCn) wait.

/* Get and return received data from buffer */
return UDR0;
}

void uart_echo(void)
{

}