#include <reg51.h>
#include <stdio.h>


#define l P2
#define k P3

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
void delay(int a)
{
    int i,j;
    for(i =0 ; i<a ; i++)
    {
        for(j=0 ; j<i ; j++);
    }
}
void main(void)
 {
    while (1)
   {
		 k=0x0f;
		 for(x=0;x<4;x++){
	           if(k==r[x]){
	             z=x;
	             break;
		   } 
		 }
		 //delay(10);
		 k=0xf0;
		 for(y=0;y<4;y++){
	           if(k==c[y]){
		     q=y;
	             break;
		     } 
		 }			 
		// delay(10);
		  l=arr[z][q];
		//delay(10);  
   }
 }
