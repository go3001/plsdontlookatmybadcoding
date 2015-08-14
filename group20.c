/*
group20.c
*/

#include <avr/io.h>
#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR F_CPU/(16UL*BAUD)-1

#include "prototypes20.h"

/*declare global variables here*/

int main(void)
{
UART_Init ( MYUBRR );
uint8_t TXBUF[] = {64, 65, 66, 67, 68, 69, 70};

uint8_t txindex = 0;
while (1){
//read array
uint8_t data = TXBUF[txindex];
uint8_t digit0 = data/10 + 48;
uint8_t digit1 = data%10 + 48;
//Transmit data
UART_Transmit(digit0);
UART_Transmit(digit1);
txindex ++;
if (txindex == 7) {
	txindex = 0;
	UART_Transmit(13);
	UART_Transmit(10);
}
}
return 0;
}
