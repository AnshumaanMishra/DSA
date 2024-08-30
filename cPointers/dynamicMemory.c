#include <stdio.h>

int total;

int square(int intArg){
    return intArg*intArg;
}

int squareOfSum(int x, int y){
    int z = square(x+y);
    return z;
}

int recursion(int x){
    return x * recursion(x);
}


int main(){
    printf("\n");

    int a = 4, b = 8;
    total = squareOfSum(a, b);
    printf("Output = %d\n", total);

    printf("%d\n", recursion(2));

    printf("\n");
    return 0;
}