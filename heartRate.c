#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>

#define BUAD 9600
#define BRC ((F_CPU / 16 / BUAD) - 1)
#define TX_BUFFER_SIZE 128

char serialBuffer[TX_BUFFER_SIZE];
char buffer[32];
uint8_t serialReadPos = 0;
uint8_t serialWritePos = 0;
double output;
void serialWrite(char c[]);
void addCharSerial(char c);
//https://www.youtube.com/watch?v=vn3BQbOGtuA
void startConversion()
{
	ADCSRA |= (1 << ADSC);
}
void setupADC()
{
	ADMUX = (1 << REFS0) | (1 << MUX0) | (1 << MUX2);
	ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);
	DIDR0 = (1 << ADC5D);
	
	startConversion();
}



void initSerialPort  (void)  
{  
   UCSR0B = 0x08;	//Set TxENO bit to 1
   UCSR0C = 0x06;	//Set UCZ01 bi UCZ00 bits to 1
   UBRR0L = 0x67;	//Set baud rate to 9600
}

void sendData (unsigned char character)  
{  
	while (!(UCSR0A & (1<<UDRE0)));	//Check UDR0 bit, Is it empty?
	{
		UDR0 = character;			//If UDR0 bit is empty transmit character  
	} 
}
int main(void) {
  initSerialPort();
  setupADC();
  sei();

  _delay_ms(1500);
  while (1) {
    dtostre(output, buffer, 7,0);
    serialWrite(buffer);
  _delay_ms(1500);
  }
}

void serialWrite(char c[] ) {
  for(uint16_t i = 0; i < strlen(c); i++) {
    sendData(c[i]);
  }
  sendData('\n');
  sendData('\r');
  
}
ISR(USART_TX_vect) {
  if(serialReadPos != serialWritePos) {
    UDR0 = serialBuffer[serialReadPos];
    serialReadPos++;

    if (serialReadPos >= TX_BUFFER_SIZE) {
      serialReadPos++;
    }
  }
}

ISR(ADC_vect)
{
	output = ADC;
	startConversion();
}
