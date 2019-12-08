#include <stdio.h>
#include <stdlib.h>

#define N_MOD 100000007

unsigned int fib(unsigned int length);

int main(int argc,char *argv[])
{
	int i;
	unsigned int input;
	unsigned int output;
	
	printf("���l����͂��Ă�������");
	scanf("%d",&input);
	
	//�t�B�{�i�b�`�v�Z(�I�[�o�[�t���[���l���Ȃ�)
	output = fib(fib(input)) % N_MOD;
	
	printf("%d",output);
}

unsigned int fib(unsigned int length)
{
	int i;
	unsigned int temp[3];
	
	//0�`1�͒�`����Ă���
	if(length == 1)
	{
		printf("%d�̃t�B�{�i�b�`�����%d\n",length,1);
		return 1;
	}
	else if(length == 0)
	{
		printf("%d�̃t�B�{�i�b�`�����%d\n",length,0);
		return 0;
	}
	
	//Length2�ȏ�͐�������߂�
	for(i = 0; i < length;i++)
	{
		if (i < 2)
		{
			//1��2�͒�`����Ă���
			temp[i+1] = 1;
		}
		else
		{
			//�v�Z�͑O2���̘a�Ȃ̂ŁA2���l�߂Ęa�����߂�
			temp[0] = temp[1];
			temp[1] = temp[2];
			temp[2] = temp[0]+temp[1];
		}
	}
	printf("%d�̃t�B�{�i�b�`�����%d\n",length,temp[2]);
	return temp[2];
	
}