#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
	
uchar flag,a,i;
uchar code table[]="I get ";

void init()
{
	TMOD=0x20;
	TH1=0xfd;
	TL1=0xfd;
	TR1=1;
	REN=1;
	SM0=0;
	SM1=1;
	EA=1;
	ES=1;
	ET1=1;
}

void main()
{
	init();
	while(1)
	{
		if(flag==1)
		{
			ES=0;
			for(i=0;i<6;i++)
			{
				SBUF=table[i];
				while(!TI);
				TI=0;
			}
			SBUF=a;
			while(!TI);
			TI=0;
			ES=1;
			flag=0;
		}
	}
}

void ser() interrupt 4
{
	RI=0;
	a=SBUF;
	flag=1;
}