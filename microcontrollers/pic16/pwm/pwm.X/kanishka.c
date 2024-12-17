#include<pic.h>
#include<htc.h>

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);


void delay(int a)  //function to generate delay
{ 
for(int i=0; i<a;i++)
{
for(int j=0;j<144;j++);
}
}
void main()
{
 TRISC = 0;  //Clearing this bit will make PORTC as output.
CCP1CON = 0x0F;  //configuring CCP1CON register for PWM mode
T2CON = 0x04;  // enable T2CON without Prescaler and postscale configuration.
PR2 = 100;  // Set the Cycle time to 100 for varying the duty cycle from 0-100
while(1)
{
CCPR1L = 75;  //generated 75% duty cycle
  delay(1);
}
}
