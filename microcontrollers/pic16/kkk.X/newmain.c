#include <pic.h>
#include <htc.h>

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

//#include <htc.h>

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);


#define l PORTC
#define k PORTD
unsigned char r[]={0x0e,0x0d,0x0b,0x07};
unsigned char c[]={0xe0,0xd0,0xb0,0x70};

unsigned char s1;
int row;
int column;
unsigned char arr[4][4]={{0x07,0x7f,0x67,0x77},{0x66,0x6d,0x7d,0x7c},{0x06,0x5b,0x4f,0x39},{0x5e,0x3f,0x79,0x71}};
int x;
int y;
int z;
int q;
void delay(int a);
void main(void)
{
    TRISC=0;
    TRISD=0;
    while (1)
    {
        PORTD=0x0f;
        for(x=0;x<4;x++)
        {
            if(PORTD==r[x])
            {
                z=x;
                //break;
            }
        }
	//delay(10);
        PORTD=0xf0;
        for(y=0;y<4;y++)
        {
            if(PORTD==c[y])
            {
                q=y;
                //break;
            }
       }
       //delay(10);
       PORTC=arr[z][q];
       //delay(10);
     }
  }
       
void delay(int a)
{
    
        for(int i=0; i<a ; i++)
        {
            for(int j=0; j<i ; j++);
        }
}

