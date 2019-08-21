#include "matlab_lib.h"
#include "include/global.h"
#include <stdarg.h>
#include <stdlib.h>

#ifdef RAND_EN
int rand0()
{
	printf("rand0\n");
}
int rand1(int a)
{
	printf("rand1\n");
}
int rand2(int a, int b)
{
	printf("rand2\n");
}

int M_rand(int count, ...)
{
	va_list v;
	va_start(v, count);
	switch(count)
	{
		case 0:
		{
			
		}
		case 1:
		{
			int x1 = va_arg(v, int);
			va_end(v);
			rand1(x1);
			break;
		}
		case 2:
		{
			int x1 = va_arg(v, int);
			int x2 = va_arg(v, int);
			va_end(v);
			rand2(x1, x2);
			break;
		}
		case 3:
		{
#if 0
			int x1 = va_arg(v, int);
			int x2 = va_arg(v, int);
			int x3 = va_arg(v, int);
			va_end(v);
			func2(x1, x2, x3);
#endif
			break;
		}
		case 4:
		default:
			break;
	}
	return OK;
}
#endif

#ifdef REM_EN
Matrix rem(Matrix x1, int x2)
{
	printf("rem\n");
}
#endif

#ifdef FUNC_TEST
int main()
{
	M_rand(1,1);
	M_rand(2,2,3);
	M_rand(3,4,5,6);
	return 0;
}
#endif