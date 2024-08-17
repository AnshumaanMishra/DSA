#include <stdio.h>
#include <math.h>

class Tree{
    private:
        int* _mainTree;
        int* _root;
        int _length = 0;
    public:
        Tree(int size, int* localArray){
            _mainTree = new int[2 * size * sizeof(int)];
            for(int i = 0; i < size; i++){
                _mainTree[i] = localArray[i];
                _root = &_mainTree[0];
                _length++;
            }
        }

        int leftChild(int index){
            return _mainTree[2*index+1];
        }

        int rightChild(int index){
            return _mainTree[2*index+2];
        }

        void printTree(){
            int height = log(_length+1)/log(2);
            printf("Height = %d\n", height);
            for(int i1 = 0; i1 < height; i1++){
                for(int i2 = 0; i2 < pow(2, i1); i2++){
                    printf("%d ", _mainTree[(int)pow(2, i1) + i2 -1]);
                }
                printf("\n");
            }
        }

};

int main(){
    int passedArray[] = {1, 2, 3, 4, 5, 6, 7};
    int passedSize = sizeof(passedArray)/sizeof(int);
    Tree tree1 = Tree(passedSize, passedArray);
    printf("%d\n", tree1.leftChild(1));
    tree1.printTree();
}