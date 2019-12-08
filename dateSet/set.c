#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int year,month,day,hour,minute,second,dayweek;
int inputCheck(int *memory,char *src,char *firstPtr,char **nextptr,int srclength,int checkMin,int checkMax)
{
	int val;
	
	val = (int)strtol(firstPtr,nextptr,0);
	if(nextptr == &src[srclength])
	{
		printf("変数が足りません\n");
		return -1;
	}
	else if(val < checkMin || val > checkMax)
	{
		printf("値が大きすぎるか小さすぎます:(%d)\n",val);
		return -1;
	}
	*memory = val;
	return 0;
}
int fileClient(void)
{
	FILE *fp;
	char *fname = "dateset.sh";
	char sumes[35];
	int ret;

	fp = fopen(fname,"w");
	
	if(fp == NULL) 
	{
		printf("%s is unavailable",fname);
		return -1;
	}
	else
	{
		ret = fprintf(fp,"#!/bin/sh\r\nsudo date -s ");
		if(ret < 0)
		{
			printf("Could not write1");
			return -1;
		}
		
		ret = fprintf(fp,"\"20%d/%d/%d %d:%d:%d\"\n",year,month,day,hour,minute,second);
		if(ret < 0)
		{
			printf("Could not write2");
			return -1;
		}
		ret = fprintf(fp,"exit 0");
		if(ret < 0)
		{
			printf("Could not write3");
			return -1;
		}
	}
	fclose(fp);
	return 0;
}

void main(void)
{
	int data[7];
	char message[256];
	int i;
	char *pmsg;
	int ret;

	printf("年/月/日,時:分:秒(曜日(日曜日は0,土曜日は6))の順で入力してください。\n");
	scanf("%s",message);
	
	//configure datetime data.
	pmsg = message;
	
	for(i = 0; i < 7; i++)
	{
		switch(i)
		{
		case 0:
			ret = inputCheck(&data[i],message,message,&pmsg,strlen(message),0,99);
			break;
		case 1:
			ret = inputCheck(&data[i],message,pmsg+1,&pmsg,strlen(message),1,12);
			break;
		case 2:
			ret = inputCheck(&data[i],message,pmsg+1,&pmsg,strlen(message),1,31);
			break;
		case 3:
			ret = inputCheck(&data[i],message,pmsg+1,&pmsg,strlen(message),0,24);
			break;
		case 4:
			ret = inputCheck(&data[i],message,pmsg+1,&pmsg,strlen(message),0,60);
			break;
		case 5:
			ret = inputCheck(&data[i],message,pmsg+1,&pmsg,strlen(message),0,61);
			break;
		case 6:
			ret = inputCheck(&data[i],message,pmsg+1,&pmsg,strlen(message),0,7);
			break;
		}
		printf("データ[%d] = %d\n",i,data[i]);
		if(ret < 0)
		{
			return;
		}
	}
	year = data[0];
	month = data[1];
	day =data[2];
	hour = data[3];
	minute = data[4];
	second = data[5]; 
	dayweek = data[6];

	ret = fileClient();
	if(ret < 0)
	{
		return;
	}
	
	system("bash dateset.sh");
	return;
}
