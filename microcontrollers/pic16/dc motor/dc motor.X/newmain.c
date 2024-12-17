#include<pic.h>
#include<htc.h>
#define L293D PORTC
void delay(int);
void main()
{
    TRISC=0x00;
    while(1)
    {
        L293D=0x0A;
        delay(100);
        L293D=0x00;
        delay(1000);
        L293D=0x05;
        delay(1000);
        L293D=0xFF;
        delay(1000);
        L293D=0x06;
        delay(1000);
        L293D=0x09;
        delay(1000);
    }
}
void delay(int b){
    for(int i=0;i<b;i++){
        for(int j=0;j<10;j++);
    }
}
        
 
