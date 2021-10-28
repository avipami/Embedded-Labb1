#ifndef SERIAL_H_
#define SERIAL_H_

#define BAUD    38400
#define F_CPU   16000000
#define MYBAUD     ((F_CPU/(16*BAUD))-1)


void uart_init(unsigned int ,int);

void uart_txchr(unsigned char chr);
void uart_ledcontrl(char *str);
void uart_getstr(char *buffer);
void printNewLine();
char uart_getchar(void);

void uart_echo(void);

#endif

