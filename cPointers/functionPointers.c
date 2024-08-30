#include <stdio.h>

void hello(char *name){
    printf("Hello %s\n", name);
}


int add(int x, int y){
    return x + y;
}


int main(){
    printf("\n");

    int c;
    int (*p)(int, int); // Must be same as argument
    p = add; // Using & is optional

    void (*ptr)();
    ptr = hello;
    ptr("Name");
    c = p(2,3); // We can use both *p and p
    printf("%d\n", c);

    printf("\n");
    return 0;
}