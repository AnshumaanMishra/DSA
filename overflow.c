#include <stdio.h>
#include <unistd.h>

int main(){
    printf("\n");
    int i = 1;
    while(1){
        printf("%d\n", i);
        i *= 2;
        sleep(1);
    }
    printf("\n");
    return 0;
}