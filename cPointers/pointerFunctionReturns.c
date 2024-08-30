#include <stdlib.h>
#include <stdio.h>

int printHelloWorld(){
    printf("Hello World\n");
}


int* add(int* a, int* b){
    int* c = (int*)malloc(sizeof(int));
    *c = (*a) + (*b);
    // printf("%d\n", c);
    return c;
}


int main(){
    printf("\n");

    int x = 2, y = 4;
    int* z = add(&x, &y);
    // printHelloWorld();
    printf("Sum = %d\n", *z);

    printf("\n");
    return 0;
}