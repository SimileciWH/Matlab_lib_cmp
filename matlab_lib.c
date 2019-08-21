#include "include/global.h"
#include <stdarg.h>
#include <stdlib.h>
#include "matlab_lib.h"

#ifdef RAND_EN
int rand0()
{
#ifdef DEBUG
	printf("rand0\n");
#endif
}
int rand1(int a)
{
#ifdef DEBUG
	printf("rand1\n");
#endif
}
int rand2(int a, int b)
{
#ifdef DEBUG
	printf("rand2\n");
#endif
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
Matrix rem(Matrix x1, float x2, int count)
{
#ifdef DEBUG
	printf("rem\n");
    printf("count = %d\n", count);
#endif

    unsigned short i;
    Matrix result;

    if(count > MATRIX_MAX_NUM)
    {
        printf("ERR beyond matrix max size 100\n");
        return INVAILD;
    }
    for(i = 0; i < count; i++)
    {
#ifdef DEBUG
        printf("fmod(x1[i], x2) = %f\n", fmod(x1[i], x2));
#endif
        result[i] = fmod(x1[i], x2);
    }

    return result;
}
#endif

#ifdef FUNC_TEST
int main()
{
#ifdef RAND_TEST
    M_rand(1,1);
    M_rand(2,2,3);
    M_rand(3,4,5,6);
#endif
#ifdef REM_TEST
    float a[] = {1,2,3,4,5,6,7};
    float b[] = {1.4,2.5,3.6,4.7,9.0,12.6};
    Matrix result;
    unsigned short i;
    int len;
    len = sizeof(a)/sizeof(float);
    printf("len =%d\n", len);
    result = rem(a, 3, len);
    for(i = 0; i < len; i++)
    {
        printf("result [int] %f\n", result[i]);
    }
    len = sizeof(b)/sizeof(float);
    result = rem(b, 4.2, len);
    for(i = 0; i < len; i++)
    {
        printf("result [float] %0.2f\n", result[i]);
    }
#endif
    return 0;
}
#endif