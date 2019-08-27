#ifndef _MATLAB_LIB_H_
#define _MATLAB_LIB_H_

#include <math.h>
#include <stdio.h>

int M_rand(int count, ...);
List_F *rem(List_F *x1, List_F x2, List_I count);
IND2SUB ind2sub(IND2SUB_BASE colAndRow, U32 x2[], U16 count);

#endif