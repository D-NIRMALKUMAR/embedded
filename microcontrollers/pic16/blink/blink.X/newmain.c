#include<pic.h>
#include<htc.h>
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

//#include <htc.h>

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);


void delay(int);
#define LED PORTA
void main()
{
while(1)
{
TRISA=0x00;
LED=0x00;
delay(1000);
LED=0xff;
delay(1000);
}
}
void delay(int a)
{
int i;
int j;
for(i=0;i<=a;i++)
{
for (j=0;j<i;j++);
}
}
