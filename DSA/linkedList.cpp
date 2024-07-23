#include <stdio.h>
#include <iostream>
using namespace std;

class linkedList{
    private:
        int size = 0;
        int sizeOfUnit = sizeof(int);
        int** mainList = (int**)malloc(size);
    public:

        void assignValue(int size, int* valueArray){
            for (int i = 0; i < size; i++){
                mainList[i][0] = valueArray[i];
            }

            for (int i = 0; i < size-1; i++){
                mainList[i][1] = (&mainList[i+1][0]);
            }
        }

        void printArray(){
            for (int i = 0; i < size; i++){
                printf("%d %d", mainList[i][0], mainList[i][1]);
            }
        }

        linkedList(int localSize, int* localArray){
            int** mainList = (int**)malloc(sizeOfUnit*localSize*2);
            size = localSize;
            assignValue(localSize, localArray);
            
        }
};

int main(){
    int passedSize = 3;
    int passedArray[] = {1, 2, 3};
    linkedList list1(passedSize, passedArray);
    list1.printArray();
    return 0;
}

