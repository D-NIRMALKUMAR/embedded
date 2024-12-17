#include<reg51.h>
sbit Led  = P2^1;    //pin connected to toggle Led
sbit Switch =P1^1;  //Pin connected to toggle led
int main()
{
    Led  = 0; //configuring as output pin
    Switch = 1; //Configuring as input pin
    while(1) //Continuous monitor the status of the switch.
    {
        if(Switch == 0)
        {
            Led =1; //Led On
        }
        else
        {
            Led =0; //Led Off
        }
    }
    return 0;
	}