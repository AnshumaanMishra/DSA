#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("\n");
    
    // ---------- MALLOC ----------
    // Returns void pointer that needs to be typecast
    int numOfUnits = 3;
    int *P = (int*)malloc(numOfUnits*sizeof(int)); // argument = size in bytes
    // (int*) casts void to int
    // Default value = none

    // Dereferencing to allocate Values
    printf("%d\n", P);
    *P = 2; // Same as P[0]
    *(P+1) = 4; // Same as P[1]
    *(P+2) = 6;

    printf("\n");
    return 0;
}