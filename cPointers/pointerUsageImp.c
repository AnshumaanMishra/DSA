#include <stdio.h>

void increment(int* p){
    (*p)++;
}
int main()
{
    printf("\n");
    
    int a = 5;
    increment(&a);
    
    printf("%d\n", a);

    printf("\n");
    return 0;
}
