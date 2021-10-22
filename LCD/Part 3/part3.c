/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 10/20/2021
Author  : 
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>

unsigned char str[6];
int h, m, s;

interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
    TCNT1H=0x85EE >> 8;
    TCNT1L=0x85EE & 0xff;
    s--;
    if(s == 0){
     m--; 
     s = 59;
    }
    if(m == 0){
     h--; 
     m = 59;
    }
    if(h == 0 && m == 0 && s == 0){
     #asm("cli")
    }
}

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);

PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);


// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 31.250 kHz
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer Period: 1 s
// Timer1 Overflow Interrupt: On
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (1<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x85;
TCNT1L=0xEE;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);


lcd_init(16);
lcd_clear();
lcd_puts("press first button to set");
// Global enable interrupts


while (1)
      {
        if(PINB.6){ 
            #asm("cli")
            lcd_clear();
            lcd_puts("set hour:");
            delay_ms(250);
            while(!PINB.6){ 
                if(PINB.7){
                    h++;
                    delay_ms(50);
                }
                sprintf(str,"%d:--:--",h);
                lcd_clear();
                delay_ms(150);
                lcd_puts(str);
                delay_ms(150);    
            }
            delay_ms(250);
            while(!PINB.6){ 
                if(PINB.7){
                    m++;
                    delay_ms(50);
                }
                sprintf(str,"--:%d:--",m);
                lcd_clear();
                delay_ms(200);
                lcd_puts(str);
                delay_ms(200);    
            }
            delay_ms(250);
            while(!PINB.6){ 
                if(PINB.7){
                    s++;
                    delay_ms(50);
                }
                sprintf(str,"--:--:%d",s);
                lcd_clear();
                delay_ms(200);
                lcd_puts(str);
                delay_ms(200);    
            }
            #asm("sei")
            delay_ms(500);
        }
        sprintf(str,"%d:%d:%d",h,m,s);  
        lcd_clear();
        lcd_puts(str);
        delay_ms(10);

      }
}
