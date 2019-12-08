#include <stdio.h>

void main(void)
{
	int a;
	
	scanf("%d",&a);

	switch(a)
	{
	case 0:
	case 1:
	case 2:
		printf("これは%dです",a);
		break;
	case 3:
	case 4:
	case 5:
		printf("これは3～5です");
		break;
	default:
		printf("数字にしてください");
		break;
	}
	return;
}
