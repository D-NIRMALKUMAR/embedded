#include<pic.h>
#include<htc.h>

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

//#include <htc.h>

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);


void main()
{
    TRISD=1;
    TRISC=0;
    while(1) 
    {
        if(PORTD == 0x01)
        {
            PORTC = 0x01;
            
        }
}
}

