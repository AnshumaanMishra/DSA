#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("\n");
    
    
    int a;
    int *p;

    p = (int*)malloc(sizeof(int));
    printf("%d %d\n", p, *p);
    *p = 10;
    printf("%d %d\n", p, *p);
    free(p); // When freed, assigns at same point
    printf("%d %d\n", p, *p);
    
    p = (int*)malloc(sizeof(int));
    printf("%d %d\n", p, *p);
    *p = 20;
    printf("%d %d\n", p, *p);


    printf("\n");
    return 0;
}