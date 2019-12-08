#include <stdio.h>

void main(void)
{
	int i,j,k;
	char temp[10];
	int ret = 0;
	char c;

	c = getchar();
	for(i = 0; i < 10; i++)
	{
		if((c < 0x30 ) || (c > 0x39))
		{
			break;
		}
		else
		{
			temp[i] = c;
			if( i < 9 )
			{
				temp[i+1] = 0x00;
			}
			c = getchar();
		}
	}
	for(j = 0; j < i; j++)
	{
		int keta = 1;
		for(k = i - j - 1; k > 0; k--)
		{
			keta *= 10;
		}
		ret += (temp[j] - 0x30) * keta;
	}
	printf("Output : %d",ret);

}
