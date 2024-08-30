#include <stdio.h>

int main()
{
    printf("\n");

    int arr[5] = {1,2,3,4,5};
    int* p = &arr[0];
    printf("%d %d\n", p, *p);
    printf("%d %d\n", p+1, *(p+1));
    printf("%d %d\n", p+2, *(p+2));

    int* p2 = arr;  // 1st element by default
    printf("%d %d\n", p2, *p2);
    
    // arr[i] is equivalent to *(p+i)
    printf("%d %d\n", arr[1], *(p2+1));

    printf("\n");
}
