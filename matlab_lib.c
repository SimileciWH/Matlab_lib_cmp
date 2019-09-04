#include "include/global.h"
#include <stdarg.h>
#include <stdlib.h>
#include "matlab_lib.h"

#ifdef RAND_EN
RAND rand0()
{
#ifdef DEBUG
	printf("rand0 in (0,1)\n");
#endif
    RAND result;
    result.randArry[0][0] = ((float)(rand()%10000)) / 10000;
    return result;
}
RAND rand1(int a)
{
#ifdef DEBUG
	printf("rand1\n");
#endif
    RAND result;
    U16 i, j;

    if(a > MAX_NUM_ROW)
    {
        printf("[Fatal ERR] %d > MAX_NUM(%d)\n", a, MAX_NUM_ROW);
        result.randArry[0][0] = ERR;
        return result;
    }
    for(i = 0; i < a; i++)
    {
        for(j = 0; j < a; j++)
        {
            result.randArry[i][j] = ((float)(rand()%10000)) / 10000;
        }
    }
    return result;
}
RAND rand2(int a, int b)
{
#ifdef DEBUG
	printf("rand2\n");
#endif
    RAND result;
    U16 i, j;

    if(a > MAX_NUM_ROW || b > MAX_NUM_COL)
    {
        printf("[Fatal ERR] %d_%d > MAX_NUM(%d_%d)\n", a, b, MAX_NUM_ROW, MAX_NUM_COL);
        result.randArry[0][0] = ERR;
        return result;
    }
    for(i = 0; i < a; i++)
    {
        for(j = 0; j < b; j++)
        {
            result.randArry[i][j] = ((float)(rand()%10000)) / 10000;
        }
    }
    return result;
}

RAND M_rand(int count, ...)
{
    va_list v;
    va_start(v, count);
    RAND result;

	switch(count)
	{
        case 0:
        {
            result = rand0();
            break;
        }
        case 1:
        {
            int x1 = va_arg(v, int);
            va_end(v);
            result = rand1(x1);
            break;
        }
        case 2:
        {
            int x1 = va_arg(v, int);
            int x2 = va_arg(v, int);
            va_end(v);
            result = rand2(x1, x2);
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

#ifdef SETDIFF_EN
SETDIFFTYPE setdiff(List_F *A, U16 count_A, List_F *B, U16 count_B /*, U16 type*/)
{
    SETDIFFTYPE result;
    U16 i, j, count = 0, skipFlag = FALSE;

    if(MAX_NUM_COUNT < ((count_A >= count_B)?count_A: count_B))
    {
        printf("[Fatal ERR] Matrix A or B length is beyond MAX(%d)\n", MAX_NUM_COUNT);
        result.setdiff[0].setdiffType = ERR;
        return result;
    }
    for(i = 0; i < count_A; i++)
    {
#ifdef DEBUG
        printf("A[%d] = %f\n", i, A[i]);
#endif
        //remove same number in result
        if(count != 0)
        {
            for(j = 0; j < count; j++)
            {
                if(result.setdiff[j].bits.num == A[i])
                {
#ifdef DEBUG
                    printf("A[%d] = %f, sizeof(float) = %d\n", i, A[i], sizeof(float));
                    printf("result[%d] = %f\n", j, result.setdiff[j].bits.num);
#endif
                    skipFlag = TRUE;
                    break;
                }
            }
            if( skipFlag == TRUE)
            {
                skipFlag = FALSE;
                continue;
            }
        }
        //find same number in B
        for(j = 0; j < count_B; j++)
        {
            if(A[i] == B[j])
            {printf("A[%d] = %f, B[%d] = %f\n", i, A[i], j, B[j]);
                break;
            }
        }
        if(j == count_B)
        {
#ifdef DEBUG
            printf("[2] A[%d] = %f\n", i, A[i]);
#endif
            result.setdiff[count].bits.num = A[i];
            result.setdiff[count].bits.index = i;
            count++;
        }
    }
    if(i == count_A)
    {
        if(count == 0)
        {
            result.setdiff[count].bits.count = 0;
        }
        else
        {
            for(i = 0; i < count; i++)
            {
                result.setdiff[i].bits.count = count;
#if 0
                if(type == INT_SIZE)
                {
                    result.setdiff[i].bits.num = (int)(result.setdiff[i].bits.num);
                }
                else if(type == FLOAT_SIZE)
                {
                    result.setdiff[i].bits.num = (float)(result.setdiff[i].bits.num);
                }
#endif
            }
        }
        return result;
    }

}

#endif

#ifdef FUNC_TEST
int main()
{
#ifdef RAND_TEST
    RAND result;
    U16 i, j, row = 10, col =1, n = 5;
    result = M_rand(0);
    if(result.randArry[0][0] != ERR)
    {
        printf("rand in (0,1) = %f\n", result.randArry[0][0]);
    }
    else
    {
        printf("ERR\n");
    }
    result = M_rand(1,n);
    if(result.randArry[0][0] != ERR)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                printf("%f\t", result.randArry[i][j]);
            }
            printf("\n");
        }
    }
    else
        {
        printf("ERR\n");
    }
    result = M_rand(2, row, col);
    if(result.randArry[0][0] != ERR)
    {
        for(i = 0; i < row; i++)
        {
            for(j = 0; j < col; j++)
            {
                printf("%f\t", result.randArry[i][j]);
            }
            printf("\n");
        }
    }
    else
        {
        printf("ERR\n");
    }

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
#ifdef SETDIFF_TEST
    List_F a[] = {-1.4, -2.5, -3.2, 4.6, 5, 6, 1.7, 1, -2, 2, -3};
    List_F b[] = {-2.5, 6.3, 5.2, 10.1, 0.5, 9.2};
    U16 count_A = length(a, INT_SIZE);
    U16 count_B = length(b, INT_SIZE), count;
    SETDIFFTYPE result;
    U16 i;

    result = setdiff(a, count_A, b, count_B);
    if(result.setdiff[0].setdiffType == ERR)
    {
        printf("[ERR]\n");
    }
    count = result.setdiff[0].bits.count;
    printf("count = %d\n", count);
    if(count == 0)
    {
        printf("All number in A is also in B\n");
    }
    else
    {
        for(i = 0; i < count; i++)
        {
            printf("%f_%d\t", result.setdiff[i].bits.num, result.setdiff[i].bits.index);
        }
    }

#endif
    return 0;
}
#endif
