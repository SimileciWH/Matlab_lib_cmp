#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <string.h>

#define FUNC_TEST
#define REM_TEST
//#define RAND_TEST
#define DEBUG

#define RAND_EN
#define REM_EN

typedef enum _return_type
{
    ERR,
    OK,
}return_type;

#define MATRIX_MAX_NUM 100
#define Matrix float*  // define Matrix
typedef enum _return_Matrix_type
{
    INVAILD,
    VAILD,
}return_Matrix_type;
#endif