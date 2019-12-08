#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int i;
	int com = 0;
	printf("%d\r\n",argc);
	
	for(i = 0; i < argc;i++)
	{
		printf("%s\r\n",argv[i]);
	}
	while(com != 254)
	{
		//end command = 254
		printf("If you want to end, type 254\r\n");
		printf("Please input command code:");
		scanf("%d",&com);
		
		
		printf("\r\ncommand is %d\r\n",com);
	}
}
