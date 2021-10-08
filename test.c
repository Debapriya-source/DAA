#include "matrix.h"
int main(){
    int **a=matAllocate(2,2),**b=matAllocate(2,2);
    matInput(a,2,2);
    matInput(b,2,2);
    matDisplay(squareMatMul(a,b),2,2);
}