/*********************/
/*
functionsxx.c
*/

#include <avr/io.h>
void UART_Init(unsigned int xyz)
{
	UBRR0H = (xyz>>8) ;
	UBRR0L = xyz;
	UCSR0B |= (1 << TXEN0);
	UCSR0C |= (1<<UCSZ00)|(1<<UCSZ01);
		
}

void UART_Transmit(uint8_t data)
{
	
while (!(UCSR0A & (1<<UDRE0)));

	UDR0 = data;

}
// Set baud rate */
	
/* Set frame format: */
 
/* Enable Transmitter */

