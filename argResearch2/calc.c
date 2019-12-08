#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int a,b;
	
	if(argc >= 3)
	{
		a = (int)strtol(argv[1],NULL,0);
		b = (int)strtol(argv[2],NULL,0);
		
		printf("WA:%d",a + b);
		printf("SA:%d",a - b);
		printf("SEKI:%d", a * b);
		printf("SHO:%d",a / b);
		printf("AMARI:%d",a % b);
		
	}
}
