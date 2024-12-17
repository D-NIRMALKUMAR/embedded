#include<pic.h>
#include<htc.h>
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);

#define L293D PORTC
void delay(int);
void main()
{
    TRISC=0x00;
    while(1)
    {
        L293D=0x01;
        delay(1000);
        L293D=0x03;
        delay(1000);
        L293D=0x02;
        delay(1000);
        L293D=0x06;
        delay(1000);
        L293D=0x04;
        delay(1000);
        L293D=0x0c;
        delay(1000);
        L293D=0x08;
        delay(1000);
        L293D=0x09;
        delay(1000);
        L293D=0x01;
        delay(1000);
    }
}
void delay(int b){
    for(int i=0;i<b;i++){
        for(int j=0;j<i;j++);
    }
}
        
 