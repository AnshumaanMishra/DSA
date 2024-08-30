#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("\n");

    // ---------- CALLOC ----------
    // Returns VOID POINTER
    int numOfUnits = 5;
    int sizeOfUnit = sizeof(int);
    void *P = calloc(numOfUnits, sizeOfUnit);
    // Default value = 0

    printf("\n");
    return 0;
}