#include <stdio.h>

int sqrt(int x);

void main(void)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int D = 0;
	int rtD = 0;

	printf("input a:");
	scanf("%d",&a);
	printf("input b:");
	scanf("%d",&b);
	printf("input c:");
	scanf("%d",&c);

	printf("(%d) x^2 + (%d) x + (%d) = 0\r\n",a,b,c);
	
	D = (b * b - 4 * a * c);
	rtD = sqrt(D);
	
	
	if(D > 0)
	{
		if(rtD * rtD != D)
		{
			printf("      %d + root( %d )\n",-1 * b, D);
			printf("x1 = ----------------\n");
			printf("           %d        \n\n", 2 * a);
			printf("      %d - root( %d )\n",-1 * b, D);
			printf("x2 = ----------------\n");
			printf("           %d        \n", 2 * a);
		}
		else
		{
			
			printf("           %d        \n",-1 * b + rtD);
			printf("x1 = ----------------\n");
			printf("           %d        \n\n", 2 * a);
			printf("           %d        \n",-1 * b - rtD);
			printf("x2 = ----------------\n");
			printf("           %d        \n", 2 * a);
		}
	}
	else if(D == 0)
	{
		if((b % a == 0) && (b % (a * 2) == 0))
		{
			printf("x =        %3d       \n",-1 * b / (2 * a));
		}
		else if(b % 2 == 0)
		{
			printf("           %3d       \n",-1 * b / 2);
			printf("x =  ----------------\n");
			printf("           %3d       \n",a);
		}
		else
		{
			printf("           %3d       \n",-1 * b);
			printf("x =  ----------------\n");
			printf("           %3d       \n", 2 * a);
		}
	}
	else
	{
		printf(" No Jissu Kai");
	}
}

int sqrt(int x)
{
	int i;
	for(i = 1; i < x; i++)
	{
		if(i * i > x)
		{
			return i-1;
		}
		if(i * i == x)
		{
			return i;
		}
	}
	return 0;
}
