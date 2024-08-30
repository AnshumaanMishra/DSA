#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("\n");
    
    
    int a;
    int *p;

    p = new int;
    printf("%d %d\n", p, *p);
    *p = 10;
    printf("%d %d\n", p, *p);
    delete p; // When freed, assigns at same point
    printf("%d %d\n", p, *p);
    
    p = new int[20];
    printf("%d %d\n", p, *p);
    *p = 20;
    printf("%d %d\n", p, *p);
    delete[] p;

    printf("\n");
    return 0;
}