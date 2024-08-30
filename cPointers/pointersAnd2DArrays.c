#include <stdio.h>


// 1D Argument
void func(int *A){
    printf("%d\n", A);
}

//2D argument
void func2(int (*A)[2]){
    printf("%d\n", A);
}

int main(){
    printf("\n");

    int a[3][2][2] = {{{2,5}, {7,9}},{{3,4}, {6,1}}, {{0,8}, {11,13}}};
    printf("%d %d %d %d \n", a, *a, a[0], &a[0][0]);
    func(a[0][0]);
    int b[2][2] = {{1,2}, {3,4}};
    func2(b);

    printf("\n");
    return 0;
}
