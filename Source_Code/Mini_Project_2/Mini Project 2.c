#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

unsigned  char num1 = 0;
unsigned  char num2 = 0;
unsigned  char num3 = 0;
unsigned  char num4 = 0;
unsigned  char num5 = 0;
unsigned  char num6 = 0;




void STOP_WATCH_Init(void){

	DDRC |= 0x0F;
	PORTC &= 0xF0;

	DDRA |= 0x3F;
	PORTA &= 0xC0;




}




void TIMER1_CTC_Init(void){

	TCCR1A = (1<<FOC1A);
	TCCR1B = (1<<WGM12) | (1<<CS11) | (1<<CS10);

	TIMSK |=(1<<OCIE1A);
	SREG |= (1<<7);

	TCNT1 = 0;
	OCR1A = 15625;





}


void INT0_Init(void){

	DDRD &=~ (1<<PD2);
	PORTD |= (1<<PD2);

	MCUCR |= (1<<ISC01);
	GICR |=(1<<INT0);
	SREG |=(1<<7);


}

void INT1_Init(void){
	DDRD &=~ (1<<PD3);

	MCUCR |= (1<<ISC01) |(1<<ISC11);
	GICR |=(1<<INT1);
	SREG |=(1<<7);






}

void INT2_Init(void){
	DDRB &=~ (1<<PB2);
	PORTB |= (1<<PB2);

	MCUCSR &=~(1<<ISC2);
	GICR |=(1<<INT2);

	SREG |=(1<<7);





}



int main(void){

	STOP_WATCH_Init();
	TIMER1_CTC_Init();
	INT0_Init();
	INT1_Init();
	INT2_Init();

	while(1){

		PORTA = (PORTA & 0xC0)|(1<<PA0);
		PORTC = (PORTC & 0xF0)| (num1 & 0x0F);
		_delay_us(100);

		PORTA = (PORTA & 0xC0)|(1<<PA1);
		PORTC = (PORTC & 0xF0)| (num2 & 0x0F);
		_delay_us(100);

		PORTA = (PORTA & 0xC0)|(1<<PA2);
		PORTC = (PORTC & 0xF0)| (num3 & 0x0F);
		_delay_us(100);

		PORTA = (PORTA & 0xC0)|(1<<PA3);
		PORTC = (PORTC & 0xF0)| (num4 & 0x0F);
		_delay_us(100);

		PORTA = (PORTA & 0xC0)|(1<<PA4);
		PORTC = (PORTC & 0xF0)| (num5 & 0x0F);
		_delay_us(100);

		PORTA = (PORTA & 0xC0)|(1<<PA5);
		PORTC = (PORTC & 0xF0)| (num6 & 0x0F);
		_delay_us(100);

	}

}

ISR(TIMER1_COMPA_vect){

	num1++;

	if (num1 > 9){
		num1 = 0;
		num2 ++;

	}

	if (num2 == 6){
		num2 = 0;
		num3 ++;

	}

	if (num3 > 9){
		num3 = 0;
		num4 ++;

	}

	if (num4 == 6){
		num4 = 0;
		num5 ++;

	}
	if (num5 > 9){
		num5 = 0;
		num6 ++;

	}
	if (num6 > 9){
		num1=0, num2=0, num3=0, num4=0, num5=0, num6=0;


	}


}

ISR (INT0_vect){

	num1=0, num2=0, num3=0, num4=0, num5=0, num6=0;
	TIMER1_CTC_Init();


}


ISR (INT1_vect){

	TCCR1B &=~ (1<< CS11) & ~(1<<CS10);




}


ISR (INT2_vect){

	TCCR1B |= (1<<CS11) | (1<<CS10);

}
