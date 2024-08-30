#include <stdio.h>
#include <string.h>

// int main(){
//     printf("\n");

//     // Strings need to be larger than required size to accomodate the null character

    // char arr[6];
    // arr[0] = 'J';
    // arr[1] = 'o';
    // arr[2] = 'h';
    // arr[3] = 'n';
    // arr[4] = '\0'; // Only prints until the terminator character "\0"
    // arr[5] = 'S';
    // printf("String = %s\n", arr);
    // printf("%d\n", strlen(arr));
    // printf("\n");
    // return 0;
// }



// int main(){
//     char C[4];
//     C[0] = 'J';
//     C[1] = 'o';
//     C[2] = 'h';
//     C[3] = 'n';
//     printf("%s\n", C);
// }

// Custom print function

void printString(char* stringPointer){
    int i = 0;
    while(*stringPointer != '\0'){
        printf("%c", *(stringPointer));
        stringPointer++;
    }
    printf("\n");
}


int main(){
    printf("\n");

    char c1[6] = "Hello"; // String automatically adds null terminator
    char* c2;
    c2 = c1;
    *(c2+1) = 'a';
    // printf("%s\n", c1);
    printString(c2);

    printf("\n");
    return 0;
}
