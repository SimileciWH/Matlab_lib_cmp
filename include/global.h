#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <string.h>

#define FUNC_TEST
#define DEBUG
//#define REM_TEST
//#define RAND_TEST
//#define LENGTH_TEST
//#define IND2SUB_TEST
//#define NUM2STR_TEST

#define RAND_EN
#define REM_EN
#define LENGTH_EN
#define IND2SUB_EN
#define NUM2STR_EN

typedef unsigned char       U8;
typedef unsigned short      U16;
typedef unsigned long       U32;
typedef unsigned long long  U64;

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

#ifdef IND2SUB_EN
#define COL_ROW_MAX_NUM 200
typedef union _IND2SUB_BASE
{
    struct
    {
        U16 col;
        U16 row;
    }bit;
    U32 colAndRow;
}IND2SUB_BASE, *pIND2SUB_BASE;

typedef struct _IND2SUB
{
    IND2SUB_BASE ind2sub[COL_ROW_MAX_NUM];
}IND2SUB;
#endif

#ifdef NUM2STR_EN
#define MAX_NUM_DIGIT 10
#define MAX_NUM_COUNT 200
typedef struct _NUM2STR
{
    char num2str[MAX_NUM_COUNT][MAX_NUM_DIGIT];
}NUM2STR;
#endif


#endif