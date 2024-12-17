#include<reg51.h>
//sbit Led  = P2^1;    //pin connected to toggle Led
//sbit Switch =P1^1; 
#define d P2
#define l P3
 //Pin connected to toggle led
void main(void)
{
    d = 0;
    char r[4] = {0x07,0x0B,0x0D,0x0E};
    char c[4] = {0x70,0xB0,0xD0,0xE0};
    char 7[4][4] = {{0x3f,0x06,0x5b,0x4f},{0x66,0x6d,0x7d,0x07},{0x7f,0x67,0x77,0x7c},{0x39,0x5e,0x79,0x71}};
    int i;
    int j;
    //Led  = 0; //configuring as output pin
    //Switch = 1; //Configuring as input pin
    while(1) //Continuous monitor the status of the switch.
    {
      for(i=0;i<4;i++){
        for(j=0;j<4;j++){
	    if(r[i]&c[j]==0)
	    { 
	     l=7[i][j];
	     break;
	    }
	     }
      }
    }
 }