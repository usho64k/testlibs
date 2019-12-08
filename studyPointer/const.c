#include <stdio.h>

void pointerConst(int * const pa)
{
	//Pointer is readonly.
	int abc = 0;
	//pa = &abc;     // <-- compile error
	*pa = 2;
	printf("pointerConst pa:[%08x]:%d\r\n",(unsigned int)pa,*pa);
}

void valueConst(const int *pa)
{
	//Value is readonly.
	int abc = 0;
	pa = &abc;
	//*pa = 2;     // <-- compile error
	printf("valueConst pa:[%08x]:%d\r\n",(unsigned int)pa,*pa);
}

void which6Const(const int * pa)
{
	//Value is readonly.
	int abc = 0;
	pa = &abc;
	//*pa = 2;     // <-- compile error
	printf("valueConst pa:[%08x]:%d\r\n",(unsigned int)pa,*pa);
}

void bothConst(const int * const pa)
{
	int abc = 0;
	//pa = &abc;	// <-- compile error
	//*pa = 2;		// <-- compile error
	printf("bothConst pa:[%08x]:%d\r\n",(unsigned int)pa,*pa);
}

void which1Const(int const *pa)
{
	//Which is readonly?
	int abc = 0;
	pa = &abc;		// <-- compile OK
	//*pa = 2;		// <-- compile error
	printf("which1Const pa:[%08x]:%d\r\n",(unsigned int)pa,*pa);
}

void which5Const(int const * pa)
{
	//Which is readonly?
	int abc = 0;
	pa = &abc;		// <-- compile OK
	//*pa = 2;		// <-- compile error
	printf("which1Const pa:[%08x]:%d\r\n",(unsigned int)pa,*pa);
}

void which2Const(const int const *pa)
{
	//Which is readonly?
	int abc = 0;
	pa = &abc;		// <-- compile OK
	//*pa = 2;		// <-- compile error
	printf("which2Const pa:[%08x]:%d\r\n",(unsigned int)pa,*pa);
}

void which4Const(const int const * pa)
{
	//Which is readonly?
	int abc = 0;
	pa = &abc;		// <-- compile OK
	//*pa = 2;		// <-- compile error
	printf("which2Const pa:[%08x]:%d\r\n",(unsigned int)pa,*pa);
}

void which3Const(int const * const pa)
{
	//Which is readonly?
	int abc = 0;
	//pa = &abc;	// <-- compile error
	//*pa = 2;		// <-- compile error
	printf("which3Const pa:[%08x]:%d\r\n",(unsigned int)pa,*pa);
}
void main(void)
{
	int a = 10;
	int *p = &a;

	//they have a argument are "int pointer" type.
	pointerConst(p);
	valueConst(p);
	
	printf("A:[%08x]:%d\r\n",&a,a);
	
}
