#include <stdio.h>
#include <time.h>
#include <math.h>

void main(void)
{
  int n,a,b,c;
  clock_t start,end;
  start = clock();
  n = 1;
  for ( n = 2; n < 1000000; n++)
  {
    b = 0;
    for(a = 2; (double)a < sqrt(n/1.0); a++)
    {
        if( n % a == 0)
        {
           b = n / a;
           c = 1;
        }
    }
    if(b != 0)
    {
      printf("%dは%dで割り切れます\r\n",n,b);
    }
    else
    {
      printf("%dは素数です\r\n",n);
    }
  }
  end = clock();
  printf("%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);
}
