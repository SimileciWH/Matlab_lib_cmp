#ifndef _MATLAB_LIB_H_
#define _MATLAB_LIB_H_

#include <math.h>
#include <stdio.h>

int M_rand(int count, ...);
List_F *rem(List_F *x1, List_F x2, List_I count);
IND2SUB ind2sub(IND2SUB_BASE colAndRow, U32 x2[], U16 count);
NUM2STR num2str(List_F *num, U8 numOfDigits, U16 count);
ZEROS zeros(int count, ...);
SETDIFFTYPE setdiff(List_F *A, U16 count_A, List_F *B, U16 count_B /*, U16 type*/);
#endif
