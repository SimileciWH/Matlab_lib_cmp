#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <string.h>

#define FUNC_TEST
#define DEBUG
#define REM_TEST
//#define RAND_TEST
#define LENGTH_TEST


#define RAND_EN
#define REM_EN
#define LENGTH_EN

typedef enum _return_type
{
    ERR,
    OK,
}return_type;

#define MATRIX_MAX_NUM 100
typedef float List_F;
typedef int List_I;
typedef enum _return_Matrix_type
{
    INVAILD,
    VAILD,
}return_Matrix_type;

#define INT_SIZE sizeof(int)
#define FLOAT_SIZE sizeof(float)
#endif