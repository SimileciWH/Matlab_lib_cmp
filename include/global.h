#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <string.h>

#define FUNC_TEST
#define DEBUG
//#define REM_TEST
#define RAND_TEST
//#define LENGTH_TEST
//#define IND2SUB_TEST
//#define NUM2STR_TEST
//#define ZERO_TEST
//#define SETDIFF_TEST

#define RAND_EN
#define REM_EN
#define LENGTH_EN
#define IND2SUB_EN
#define NUM2STR_EN
#define ZERO_EN
#define SETDIFF_EN

typedef unsigned char       U8;
typedef unsigned short      U16;
typedef unsigned long       U32;
typedef unsigned long long  U64;
typedef char       S8;
typedef short      S16;
typedef long       S32;
typedef long long  S64;
typedef float      F32;

#define M_PI PI;

typedef enum _return_type
{
    FALSE,
    TRUE,
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
#define MAX_NUM_COL 200
#define MAX_NUM_ROW 200


#ifdef RAND_EN
typedef struct _RAND
{
    float randArry[MAX_NUM_ROW][MAX_NUM_COL];
}RAND;
#endif

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

#ifdef ZERO_EN
typedef struct _ZEROS
{
    U8 zeros[MAX_NUM_ROW][MAX_NUM_COL];
}ZEROS;
#endif

#ifdef SETDIFF_EN
typedef union _SETDIFF
{
    struct
        {
        F32 num;
        U32 index: 16;
        U32 count: 16;
        }bits;
     S32 setdiffType;
}SETDIFF;
typedef struct
{
    SETDIFF setdiff[MAX_NUM_COUNT];
}SETDIFFTYPE;
#endif

#endif
