#include <pic.h>
#include <htc.h>

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

//#include <htc.h>

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);


#define k PORTC
unsigned char arr[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x67,0x77,0x7c,0x39,0x5e,0x79,0x71};
void delay(int a);
void main(void)
{
    TRISD=0;
    TRISC=0;
    while (1)
    {
         for(int i=0; i<16 ; i++)
        {
            
	      k=arr[i];
	      delay(1000);
	      
	    
        }
     }
  }
       
void delay(int a)
{
    
        for(int i=0; i<a ; i++)
        {
            for(int j=0; j<i ; j++);
        }
}

