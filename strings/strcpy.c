#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
	char myData1[256] = {0x30,0x31,0x32,0x33,0x34,0x35};
	char myData2[256] = {0x49,0x48,0x47,0x46,0x45,0x44,0x43,0x42,0x41};
	
	char *myPointer1 = myData1;
	char *myPointer2 = myData2;
	
	int i;
	
	memcpy(myPointer2,myPointer1,256);
	
	//ˆê‰ž“ú–{Œê‚à“ü‚é‚Í‚¸‚È‚Ì‚Å‚·
	printf("myPointer:%p \n",myPointer1);
	printf("myPointer:%p \n",myPointer2);
	printf("myData:%s\n",myPointer1);
	printf("myData:%s\n",myPointer2);
	*(myPointer1 + 256) = 0x98;
	printf("%x\n",*(myPointer1+256));
	
	for(i = 0; i < 256; i++)
	{
		printf(" %d ",myData1[i]);
	}
	printf("\n");
}