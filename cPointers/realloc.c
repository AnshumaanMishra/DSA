#include <stdio.h>
#include <stdlib.h>

int main(){
    int sizeOfArray;
    int sizeOfUnit = sizeof(int);
    printf("Enter the size of the array: \n");
    scanf("%d", &sizeOfArray);

    // We cannot have array with size as a variable, hence use malloc or calloc
    // With malloc, printing without initialisation will give garbage value
    int *A = (int*)malloc(sizeOfArray*sizeOfUnit);
    printf("%d\n", A); 
    // *(A+8) = 10;

    for(int i = 0; i < sizeOfArray; i++){
        int temp = 0;
        scanf("%d", &temp);
        *(A+i) = temp;
        // printf("%d\n", *(A+i));
    }

    // ---------- REALLOC ----------
    int newSizeMultiplier = 2;
    int *B = (int*)realloc(A, newSizeMultiplier*sizeOfArray*sizeOfUnit);
    // If consecutive memory blocks are free, same block is extended with new label. Else new allocated
    // On decreasing size, GIF is taken
    printf("%d\n", B); 

    // ---------- FREE ----------
    // free(A); // Now Garbage value will be printed but we can modify value
    for(int i = 0; i < sizeOfArray; i++){
        printf("i = %d, Value at A[i] = %d\n", i, *(A+i));
    }

    return 0;
}