#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>
#include <string.h>

int main(){
    printf("\n");

    // -------Pointer to Pointer--------

    int a = -710588032;
    int* p = &a;
    // *p = 6;
    int** q = &p; // Double *
    int*** r = &q; // Triple *
    printf("Pointer 1: %d Value: %d\n", p, *p);
    printf("Pointer 2: %d Value: %d\n", q, *q);
    printf("Pointer 3: %d Value: %d\n", r, *r);
    printf("\n");
    return 0;
}
