/*
 * GasSensorPIDLabView.c
 *
 * Created: 10/29/2019 1:49:59 AM
 * Author : Shofuwan
 */ 
#ifndef F_CPU
	#define F_CPU 16000000UL
#endif
#define UBRR 103 // 9600bps, U2X Register 0

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

/****** SENSOR GAS *******/
struct MQ2_Data{
	float Gas_Value;
	float PPM_Value;
	float CO2_Value;
};

void MQ2_Init();
struct MQ2_Data MQ2_Read();
/****** SENSOR GAS *******/

/****** USART COM *******/
void USART_Init();
unsigned char USART_Read(FILE *stream);
void USART_Write(char c, FILE *stream);

FILE usart_output = FDEV_SETUP_STREAM(USART_Write, NULL, _FDEV_SETUP_WRITE);
FILE usart_input = FDEV_SETUP_STREAM(NULL, USART_Read, _FDEV_SETUP_READ);
/****** USART COM *******/

/****** PID CONTROL *******/
struct PID{
	float Kp_Value;
	float Ki_Value;
	float Kd_Value;
};

void PID_Init();
/****** PID CONTROL *******/

/****** PWM SIGNAL GENERATOR ******/
void PWM_Init();
void PWM_Write(struct PID motor);
/****** PWM SIGNAL GENERATOR ******/

/****** String Parsing ******/
struct String{
	char Data_Char[100];
	float Data_Float[100];
};

struct String String_Remove(char c);
struct String String_Filter(char separator);
int String_Length();
/****** String Parsing ******/

int main(void){
	USART_Init();
	MQ2_Init();
	PWM_Init();

	struct PID motor;
	struct MQ2_Data mq2;

    while (1){
		
    }
}

/****** SENSOR GAS *******/
void MQ2_Init(){
	ADMUX |= (1<<REFS0); // Select MUX 0
	ADCSRA |= (1<<ADEN) | (1<<ADPS0) | (1<<ADPS1) | (ADPS2); // 125KHz
}
struct MQ2_Data MQ2_Read(){
	ADCSRA |= (1<<ADSC);
	while((ADCSRA & (1<<ADSC)));
	//return ADCW;
	
	// Conversion formula
}
/****** SENSOR GAS *******/

/****** USART COM *******/
void USART_Init(){
	UBRRL = UBRR;
	UBRRH = (UBRR>>8);
	UCSRB |= (1<<RXEN) | (1<<TXEN);
	UCSRC |= (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
	
	stdout = &usart_output;
	stdin = &usart_input;
}
unsigned char USART_Read(FILE *stream){
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}
void USART_Write(char c, FILE *stream){
	while(!(UCSRA & (1<<UDRE)));
	UDR = c;
}
/****** USART COM *******/

/****** String Parsing ******/
struct String String_Remove(char c){
	char data[100] = "";
	struct String str;
	int len = 0;
	
	for(int x=0;x<String_Length();x++){
		if(str.Data_Char[x] != c){
			data[x]+=str.Data_Char[x];
			len++;
		}
	}
	
	for(int x=0;x<len;x++)
		str.Data_Char[x] += data[x];
	 
	 return str;
}
struct String String_Filter(char separator);
int String_Length(){
	int counter = 0;
	struct String str;
	
	for(int x=0;x<100;x++)
		if(str.Data_Char[x] != NULL)
			counter++;

	return counter;
}
/****** String Parsing ******/

/****** PWM SIGNAL GENERATOR ******/
void PWM_Init(){
	
}
void PWM_Write(struct PID motor){

}
/****** PWM SIGNAL GENERATOR ******/
