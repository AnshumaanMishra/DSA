#include <stdio.h>

struct Node{
    int _value;
    Node* _leftChild;
    Node* _rightChild;
    Node* _parentNode;
};

class BinarySearchTree{
    private:
        Node* _rootNode = NULL;
        int _rootHeight;
        // int 

    public:
        BinarySearchTree(){

        }

        BinarySearchTree(int size, int* localArray){
            for(int i = 0; i < size; i++){
                insert(localArray[i]);
            }
        }

        void insert(int element){
            if(_rootNode == NULL){
                Node* tempNode = new Node;
                tempNode->_value = element;
                tempNode->_leftChild = NULL;
                tempNode->_rightChild = NULL;
                _rootNode = tempNode;
                return;
            }
            Node* currentNode = _rootNode;
            checkPosition(element, currentNode);            
        }

        int findHeight(Node* currentNode){
            if(!leftChildExists(currentNode) && !rightChildExists(currentNode)){
                return 0;
            }
            else if(leftChildExists(currentNode) && !rightChildExists(currentNode)){
                return 1 + findHeight(currentNode->_leftChild);
            }

            else if(!leftChildExists(currentNode) && rightChildExists(currentNode)){
                return 1 + findHeight(currentNode->_rightChild);
            }
            else{
                int rightHeight = findHeight(currentNode->_leftChild);
                int leftHeight = findHeight(currentNode->_rightChild);
                int value = (rightHeight > leftHeight) ? (1 + rightHeight) : (1 + leftHeight);
                return value;
            }
            return 0;
        }

        int returnMinimum(Node* currentNode){
            if(leftChildExists(currentNode)){
                return returnMinimum(currentNode->_leftChild);
            }
            return currentNode->_value;
        }

        int returnMaximum(Node* currentNode){
            if(rightChildExists(currentNode)){
                return returnMaximum(currentNode->_rightChild);
            }
            return currentNode->_value;
        }

        void checkPosition(int element, Node* currentNode){
            if((element < currentNode->_value) && leftChildExists(currentNode)){
                currentNode = currentNode->_leftChild;
                checkPosition(element, currentNode);
            }
            else if((element < currentNode->_value) && !leftChildExists(currentNode)){
                Node* tempNode = new Node;
                tempNode->_value = element;
                tempNode->_leftChild = NULL;
                tempNode->_rightChild = NULL;
                tempNode->_parentNode = currentNode;
                currentNode->_leftChild = tempNode;
            }
            else if((element > currentNode->_value) && rightChildExists(currentNode)){
                currentNode = currentNode->_rightChild;
                checkPosition(element, currentNode);
            }
            else{
                Node* tempNode = new Node;
                tempNode->_value = element;
                tempNode->_leftChild = NULL;
                tempNode->_rightChild = NULL;
                tempNode->_parentNode = currentNode;
                currentNode->_rightChild = tempNode;
            }
        }
        
        bool search(int element, Node* currentNode){
            if(currentNode->_value == element){
                return true;
            }
            else if((element < currentNode->_value) && leftChildExists(currentNode)){
                return search(element, currentNode->_leftChild);
            }
            else if((element > currentNode->_value) && rightChildExists(currentNode)){
                return search(element, currentNode->_rightChild);
            }
            return false;
        }

        bool leftChildExists(Node* currentNode){
            if(currentNode->_leftChild != NULL){
                return true;
            }
            return false;
        }
        
        bool rightChildExists(Node* currentNode){
            if(currentNode->_rightChild != NULL){
                return true;
            }
            return false;
        }

        Node* getRootNode(){
            return _rootNode;
        }

        void enterNode(Node* currentNode){
            printf("%d->", currentNode->_value);
            if(leftChildExists(currentNode)){
                enterNode(currentNode->_leftChild);
            }
            if(rightChildExists(currentNode)){
                enterNode(currentNode->_rightChild);
            }
            printf("\n");
        }

        void lengthFirstTraversal(Node* currentNode){
            printf("%d, ", currentNode->_value);
            if(leftChildExists(currentNode)){
                lengthFirstTraversal(currentNode->_leftChild);
            }
            if(rightChildExists(currentNode)){
                lengthFirstTraversal(currentNode->_rightChild);
            }
        }

        void breadthFirstTraversal(Node* currentNode){
            // printf("%d, ", _rootNode->_value);
            if(leftChildExists(currentNode))
                printf("%d, ", currentNode->_leftChild->_value);
            
            if(rightChildExists(currentNode))
                printf("%d, ", currentNode->_rightChild->_value);
            
            if(leftChildExists(currentNode)){
                breadthFirstTraversal(currentNode->_leftChild);
            }
            
            if(rightChildExists(currentNode)){
                breadthFirstTraversal(currentNode->_rightChild);
            }

        }
};

int main(){
    BinarySearchTree tree1;
    tree1.insert(5);
    tree1.insert(2);
    tree1.insert(1);
    tree1.insert(3);
    tree1.insert(4);
    tree1.insert(6);
    tree1.insert(8);
    tree1.insert(7);
    printf("%d\n", tree1.returnMaximum(tree1.getRootNode()));
    printf("%d\n", tree1.findHeight(tree1.getRootNode()));
    // tree1.enterNode(tree1.getRootNode());
    tree1.breadthFirstTraversal(tree1.getRootNode());
}