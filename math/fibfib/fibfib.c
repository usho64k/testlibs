#include <stdio.h>
#include <stdlib.h>

#define N_MOD 100000007

unsigned int fib(unsigned int length);

int main(int argc,char *argv[])
{
	int i;
	unsigned int input;
	unsigned int output;
	
	printf("数値を入力してください");
	scanf("%d",&input);
	
	//フィボナッチ計算(オーバーフローを考えない)
	output = fib(fib(input)) % N_MOD;
	
	printf("%d",output);
}

unsigned int fib(unsigned int length)
{
	int i;
	unsigned int temp[3];
	
	//0～1は定義されている
	if(length == 1)
	{
		printf("%dのフィボナッチ数列は%d\n",length,1);
		return 1;
	}
	else if(length == 0)
	{
		printf("%dのフィボナッチ数列は%d\n",length,0);
		return 0;
	}
	
	//Length2以上は数列を求める
	for(i = 0; i < length;i++)
	{
		if (i < 2)
		{
			//1と2は定義されている
			temp[i+1] = 1;
		}
		else
		{
			//計算は前2項の和なので、2項詰めて和を求める
			temp[0] = temp[1];
			temp[1] = temp[2];
			temp[2] = temp[0]+temp[1];
		}
	}
	printf("%dのフィボナッチ数列は%d\n",length,temp[2]);
	return temp[2];
	
}