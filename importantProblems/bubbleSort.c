
int compare(int innerIterator, int flag, int *array){
    if(flag==0){
        if(*(array + innerIterator) > *(array + 1 + innerIterator)){
            return 1;
        }
    }
    else if(flag==1){
        if(*(array + innerIterator) < *(array + 1 + innerIterator)){
            return 1;
        }
    }
    return 0;
}


void bubbleSort(int *array, int size, int flag){
    // Outer loop
    int temp;
    for(int outerIterator = size-1; outerIterator >= 1; outerIterator--){
        // Inner Loop
        for(int innerIterator = 0; innerIterator < outerIterator; innerIterator++ ){
            int (*p)(int, int, int*) = compare; // Comparison with flag
            if(p(innerIterator, flag, array)){
                temp = *(array + 1 + innerIterator);
                *(array + 1 + innerIterator) = *(array + innerIterator);
                *(array + innerIterator) = temp;
            }
        }
    }
}

void printArr(int *arr, int size){
    for(int iterator = 0; iterator < size; iterator++){
        printf("%d\n", *(arr + iterator));
    }
}


int main(){
    printf("\n");

    int a[] = {3, 4, 6, 1, 5, 7};
    bubbleSort(a, sizeof(a)/sizeof(int), 1); // 1 = Descending, 0 = Ascending
    printArr(a, sizeof(a)/sizeof(int));

    printf("\n");
    return 0;
}