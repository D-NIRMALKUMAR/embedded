#include<pic.h>
#include<htc.h>
void delay(int a)  //function to generate delay
{ 
for(int i=0; i<a;i++)
{
for(int j=0;j<i;j++);
}
}
/*void main()
{
 TRISC = 0;  //Clearing this bit will make PORTC as output.
CCP1CON = 0x0F;  //configuring CCP1CON register for PWM mode
//T2CON = 0x04;  // enable T2CON without Prescaler and postscale configuration.
T2CON=0b01111110;
PR2 = 100;  // Set the Cycle time to 100 for varying the duty cycle from 0-100
while(1)
{
for(float i=12;i<35;i++){
CCPR1L = i;  //generated 75% duty cycle
delay(100);
}

}
}*/
void main()
{
TRISC=0x00;
//T2CON=0b00000100;
T2CON=0b01111110;
PR2=0b1001110000111;
CCPR1L = 0b10011100010000; //5% duty cycle
CCP1CON = 0b00111100 ;
delay(100);
CCPR1L = 0b11101010011000; //7.5% duty cycle
CCP1CON = 0b00111100 ;
delay(100);
CCPR1L = 0b100111000100000; //10% duty cycle
CCP1CON = 0b00111100 ;
delay(100);
} 

