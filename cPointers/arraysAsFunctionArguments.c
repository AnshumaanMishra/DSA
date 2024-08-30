#include <stdio.h>

int sumOfElements(int *arrayPointer, int size){
    float sum = 0;
    for(int i = 0; i < size; i++){
        sum += *(arrayPointer + i); // Check arrayPointer file for reference
    }
    return sum;
}

int doubleEachElement(int *arrayPointer, int size){
    for(int i = 0; i < size; i++){
        *(arrayPointer+i) = 2*(*(arrayPointer+i));
    }
    return 0;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    int *arrayPointer = arr;
    int size = sizeof(arr)/sizeof(arr[0]);
    int i;

    for(i = 0; i < size; i++){
        printf("Element at %d = %d\n", i, arr[i]);
    } 
    
    // Sum Of Elements
    int sum = sumOfElements(arrayPointer, size);
    printf("Sum Of Elements = %d\n", sum);

    // Double Each Element
    doubleEachElement(arrayPointer, sizeof(arr)/sizeof(arr[0]));
    for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        printf("Element at %d = %d\n", i, arr[i]);
    } 

    return 0;
}
