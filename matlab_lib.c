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
List_F *rem(List_F *x1, List_F x2, List_I count)
{
#ifdef DEBUG
	printf("rem\n");
    printf("count = %d\n", count);
#endif

    List_I i;
    List_F *result = x1;

    if(count > MATRIX_MAX_NUM)
    {
        printf("ERR beyond matrix max size 100\n");
        return INVAILD;
    }
    for(i = 0; i < count; i++)
    {
        result[i] = (float )fmod(x1[i], x2);
#ifdef DEBUG
        printf("fmod(%f, %f) = %f\n", x1[i], x2, *(result + i));
#endif
    }
    return result;
}
#endif

#ifdef LENGTH_EN
#define length(a,size)   (sizeof(a) / size)
#endif

#ifdef IND2SUB_EN
IND2SUB ind2sub(IND2SUB_BASE colAndRow, U32 x2[], U16 count)
{
    U8 i;
    U32 temp_row, temp_col, max_matrix;
    IND2SUB result;

    max_matrix = colAndRow.bit.col * colAndRow.bit.row;
    if(count > COL_ROW_MAX_NUM)
    {
        printf("[Fatal err] count > MAX(%d)\n", COL_ROW_MAX_NUM);
        result.ind2sub[0].colAndRow = ERR;
        return result;
    }
    for(i = 0; i < count; i++)
    {
        if(x2[i] > max_matrix)
        {
            printf("[err] [%d] is over row_col = %d_%d\n", x2[i], colAndRow.bit.row, colAndRow.bit.col);
            result.ind2sub[0].colAndRow = ERR;
            return result;
        }
        temp_row = x2[i] % colAndRow.bit.row;
        temp_col = x2[i] / colAndRow.bit.row;
        if(temp_row == 0)
        {
            result.ind2sub[i].bit.row = colAndRow.bit.row;
            result.ind2sub[i].bit.col = temp_col;
        }
        else
        {
            result.ind2sub[i].bit.row = temp_row;
            result.ind2sub[i].bit.col = temp_col + 1;
        }
    }
    return result;
}
#endif

#ifdef NUM2STR_EN
NUM2STR num2str(List_F *num, U8 numOfDigits, U16 count)
{   
    NUM2STR result;
    U16 i;

    if(numOfDigits > MAX_NUM_DIGIT || count > MAX_NUM_COUNT)
    {
        if(numOfDigits > MAX_NUM_DIGIT)
            printf("[Fatal ERR] numOfDigits(%d) > MAX_DIGITS(%d)\n",
                   numOfDigits, MAX_NUM_DIGIT);
        else
            printf("[Fatal ERR] count(%d) > MAX_COUNT(%d)\n",
                   count, MAX_NUM_COUNT);
        result.num2str[0][0] = ERR;
        return result;
    }
    for(i = 0; i < count; i++)
    {
        
        gcvt(num[i], numOfDigits, result.num2str[i]);
#ifdef DEBUG
        printf("Original number; %f\n" , num[i]);
        printf ("Converted string; %s\n",result.num2str[i]);
#endif
    }
    return result;
}
#endif

#ifdef ZERO_EN
ZEROS zeros0()
{
    ZEROS result;
    result.zeros[0][0] = 0;
    return result;
}

ZEROS zeros1(List_I n)
{
    U16 i, j;
    ZEROS result;

    if(n >= MAX_NUM_ROW || n >= MAX_NUM_COL)
    {
        printf("[Fatal][ERR] n is beyond! [%d,%d]\n", MAX_NUM_ROW, MAX_NUM_COL);
        result.zeros[0][0] = ERR;
        return result;
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            result.zeros[i][j] = 0;
        }
    }
    return result;
}
ZEROS zeros2(List_I row, List_I col)
{
    U16 i, j;
    ZEROS result;

    if(row >= MAX_NUM_ROW || col >= MAX_NUM_COL)
    {
        printf("[Fatal][ERR] n is beyond! [%d,%d]\n", MAX_NUM_ROW, MAX_NUM_COL);
        result.zeros[0][0] = ERR;
        return result;
    }
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            result.zeros[i][j] = 0;
        }
    }
    return result;

}
ZEROS zeros(int count, ...)
{
    ZEROS result;
    va_list v;
    va_start(v, count);

    switch(count)
    {
        case 0:
        {
            result = zeros0();
            break;
        }
        case 1:
        {
            int x1 = va_arg(v, int);
            va_end(v);
            result = zeros1(x1);
            break;
        }
        case 2:
        {
            int x1 = va_arg(v, int);
            int x2 = va_arg(v, int);
            va_end(v);
            result = zeros2(x1, x2);
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
    List_F a[] = {1,2,3,4,5,6,7};
    List_F b[] = {1.4,2.5,3.6,4.7,9.0,12.6};
    List_F *result;
    List_I i;
    List_I len;
    len = length(a, FLOAT_SIZE);
    result = rem(a, 3, len);
    for(i = 0; i < len; i++)
    {
        printf("result [int] %f\n", result[i]);
    }
    len = length(b, INT_SIZE);
    result = rem(b, 4.2, len);
    for(i = 0; i < len; i++)
    {
        printf("result [float] %0.2f\n", result[i]);
    }
#endif
#ifdef IND2SUB_TEST
    IND2SUB result;
    IND2SUB_BASE aa;
    aa.bit.col = 3;
    aa.bit.row = 3;
    U16 count, i;
    U32 bb[] = {3,4,5,6};

    count = length(bb, INT_SIZE);
    result = ind2sub(aa, bb, count);
    if(result.ind2sub[0].colAndRow == ERR)
    {
        printf("[ERR]\n");
    }
    else
    {
        for(i = 0; i < count; i++)
        {
            printf("[%d] = (%d,%d)\n", bb[i], result.ind2sub[i].bit.row, result.ind2sub[i].bit.col);
        }
    }
#endif
#ifdef NUM2STR_TEST
    float num[] = {12.345, 34.123, 56.99999, 1234.45678, 200};
    U16 len = length(num, FLOAT_SIZE), i;
    NUM2STR result;
    U8 numOfDigits = 5;

    result = num2str(num, numOfDigits, len);
    if(result.num2str[0][0] == ERR)
    {
        printf("[ERR]\n");
    }
    else
    {
        for(i = 0; i < len; i++)
        {
            printf("origin num(%%f) = %f, convert (%%s) = %s\n", num[i], result.num2str[i]);
        }
    }
#endif
#ifdef ZERO_TEST
    ZEROS result;
    U8 i, j, row = 10, col = 15, n = 10;

    result = zeros(0);
    printf("zeros(0) = %d\n", result.zeros[0][0]);
    result = zeros(2, row, col);
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%d\t", result.zeros[i][j]);
        }
        printf("\n");
    }
    result = zeros(1, n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", result.zeros[i][j]);
        }
        printf("\n");
    }
#endif
    return 0;
}
#endif
