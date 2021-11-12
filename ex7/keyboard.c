/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 11/5/2021
Author  : 
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>
#include <alcd.h>
#include <stdio.h>
#include <delay.h>
// Declare your global variables here


unsigned char key = 20;
unsigned char str[30];



void keyboard(void)
{
//---- ROW1 ----
PORTC.4=0;
delay_us(2);
if(PINC.0==0) key='7';
if(PINC.1==0) key='4';
if(PINC.2==0) key='1';
if(PINC.3==0) key='F';
PORTC.4=1;
//---- ROW2 ----
PORTC.5=0;
delay_us(2);
if(PINC.0==0) key='8';
if(PINC.1==0) key='5';
if(PINC.2==0) key='2';
if(PINC.3==0) key='0';
PORTC.5=1;
//---- ROW3 ----
PORTC.6=0;
delay_us(2);
if(PINC.0==0) key='9';
if(PINC.1==0) key='6';
if(PINC.2==0) key='3';
if(PINC.3==0) key='E';
PORTC.6=1;
//---- ROW4 ----
PORTC.7=0;
delay_us(2);
if(PINC.0==0) key='A';
if(PINC.1==0) key='B';
if(PINC.2==0) key='C';
if(PINC.3==0) key='D';
PORTC.7=1;
}

interrupt [EXT_INT2] void ext_int2_isr(void)
{
    unsigned char p;
    PORTC=0xFF;
    for(p=0;p<5;p++)
    keyboard();
    PORTC=0x0F;
    sprintf(str," %c",key);
    lcd_puts(str);
}


void main(void)
{
// Declare your local variables here

DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (1<<PORTC3) | (1<<PORTC2) | (1<<PORTC1) | (1<<PORTC0);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: On
// INT2 Mode: Rising Edge
GICR|=0x20;
MCUCR=0x00;
MCUCSR=0x40;
GIFR=0x20;

// Global enable interrupts
lcd_init(16);
#asm("sei");

while (1)
      {    

      }
}