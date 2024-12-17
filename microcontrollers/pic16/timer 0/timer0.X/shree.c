#include<pic.h>
#include<htc.h>

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements


__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);


void t0delay();

void main()
{
  TRISB=0;
  OPTION_REG=0x07;   //Prescale is assigned to Timer 0, Prescaler value = 256, Fclk = 11.0592MHz
  while(1) {
    PORTB=0xff;
    t0delay();
    t0delay();
    PORTB=0x00;
    t0delay();
  }
}

void t0delay()          // 1 second
{
  int i;
  for(i=0;i<42;i++) {
    while(!T0IF);
    T0IF=0;
  }
}        
