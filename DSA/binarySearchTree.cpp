#include <stdio.h>
#include <stdlib.h>


struct TreeNode{
    int _value;
    TreeNode* _leftChild;
    TreeNode* _rightChild;
    TreeNode* _parentTreeNode;
};

struct QueueNode{
    TreeNode* _value;
    QueueNode* _nextQueueNodeAddress;
};

class Queue{
    private:
        TreeNode** _head;
        TreeNode** _tail;
        QueueNode* _firstQueueNode;
        QueueNode* _lastQueueNode;
        QueueNode* _container = new QueueNode;
        int _lengthOfQueue = 0;
        QueueNode* currentQueueNode = new QueueNode;
        QueueNode* prevQueueNode = new QueueNode;

    public:
        Queue(){

        }
        Queue(TreeNode* localNode){
            EnQueue(localNode);
        }
        Queue(int length, TreeNode** localArray){
            for(int i = 0; i < length; i++){
                // currentQueueNode = new QueueNode;
                if(length>0){
                    currentQueueNode = EnQueue(localArray[i]);
                }
                if(i==0){
                    _firstQueueNode = currentQueueNode;
                }
                _lastQueueNode = currentQueueNode;
            }
        }
        int getLength(){
            return _lengthOfQueue;
        }

        QueueNode* EnQueue(TreeNode* element){
            // QueueNode* currentQueueNode = _lastQueueNode;
            QueueNode* insertedQueueNode = new QueueNode;

            insertedQueueNode->_value = element;
            insertedQueueNode->_nextQueueNodeAddress = NULL;
            if(_lengthOfQueue >= 1){
                _lastQueueNode->_nextQueueNodeAddress = insertedQueueNode;
            }

            if(_lengthOfQueue < 1){
                _firstQueueNode = insertedQueueNode;
            }
            _lastQueueNode = insertedQueueNode;
            _lengthOfQueue ++;
            return insertedQueueNode;
        }

        TreeNode* DeQueue(){
            QueueNode* tempQueueNode = _firstQueueNode;
            _firstQueueNode = tempQueueNode->_nextQueueNodeAddress;
            _lengthOfQueue -- ;
            return tempQueueNode->_value;
        }

        void printQueue(){
            QueueNode* currentQueueNode = _firstQueueNode;
            for(int i = 0; i < _lengthOfQueue; i++){
                printf("%d\n", currentQueueNode->_value);
                currentQueueNode = currentQueueNode->_nextQueueNodeAddress;
            }
        }

        TreeNode* front(){
            return _firstQueueNode->_value;
        }

        bool isEmpty(){
            return _lengthOfQueue <= 0;
        }


};


class BinarySearchTree{
    private:
        TreeNode* _rootTreeNode = NULL;
        int _rootHeight;
        Queue _traversalQueue;
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
            if(_rootTreeNode == NULL){
                TreeNode* tempTreeNode = new TreeNode;
                tempTreeNode->_value = element;
                tempTreeNode->_leftChild = NULL;
                tempTreeNode->_rightChild = NULL;
                _rootTreeNode = tempTreeNode;
                // TreeNode** array = {_rootTreeNode};
                _traversalQueue = Queue(_rootTreeNode);
                return;
            }
            TreeNode* currentTreeNode = _rootTreeNode;
            checkPosition(element, currentTreeNode);            
        }

        int findHeight(TreeNode* currentTreeNode){
            if(!leftChildExists(currentTreeNode) && !rightChildExists(currentTreeNode)){
                return 0;
            }
            else if(leftChildExists(currentTreeNode) && !rightChildExists(currentTreeNode)){
                return 1 + findHeight(currentTreeNode->_leftChild);
            }

            else if(!leftChildExists(currentTreeNode) && rightChildExists(currentTreeNode)){
                return 1 + findHeight(currentTreeNode->_rightChild);
            }
            else{
                int rightHeight = findHeight(currentTreeNode->_leftChild);
                int leftHeight = findHeight(currentTreeNode->_rightChild);
                int value = (rightHeight > leftHeight) ? (1 + rightHeight) : (1 + leftHeight);
                return value;
            }
            return 0;
        }

        int returnMinimum(TreeNode* currentTreeNode){
            if(leftChildExists(currentTreeNode)){
                return returnMinimum(currentTreeNode->_leftChild);
            }
            return currentTreeNode->_value;
        }

        int returnMaximum(TreeNode* currentTreeNode){
            if(rightChildExists(currentTreeNode)){
                return returnMaximum(currentTreeNode->_rightChild);
            }
            return currentTreeNode->_value;
        }

        void checkPosition(int element, TreeNode* currentTreeNode){
            if((element < currentTreeNode->_value) && leftChildExists(currentTreeNode)){
                currentTreeNode = currentTreeNode->_leftChild;
                checkPosition(element, currentTreeNode);
            }
            else if((element < currentTreeNode->_value) && !leftChildExists(currentTreeNode)){
                TreeNode* tempTreeNode = new TreeNode;
                tempTreeNode->_value = element;
                tempTreeNode->_leftChild = NULL;
                tempTreeNode->_rightChild = NULL;
                tempTreeNode->_parentTreeNode = currentTreeNode;
                currentTreeNode->_leftChild = tempTreeNode;
            }
            else if((element > currentTreeNode->_value) && rightChildExists(currentTreeNode)){
                currentTreeNode = currentTreeNode->_rightChild;
                checkPosition(element, currentTreeNode);
            }
            else{
                TreeNode* tempTreeNode = new TreeNode;
                tempTreeNode->_value = element;
                tempTreeNode->_leftChild = NULL;
                tempTreeNode->_rightChild = NULL;
                tempTreeNode->_parentTreeNode = currentTreeNode;
                currentTreeNode->_rightChild = tempTreeNode;
            }
        }
        
        bool search(int element, TreeNode* currentTreeNode){
            if(currentTreeNode->_value == element){
                return true;
            }
            else if((element < currentTreeNode->_value) && leftChildExists(currentTreeNode)){
                return search(element, currentTreeNode->_leftChild);
            }
            else if((element > currentTreeNode->_value) && rightChildExists(currentTreeNode)){
                return search(element, currentTreeNode->_rightChild);
            }
            return false;
        }

        bool leftChildExists(TreeNode* currentTreeNode){
            return (currentTreeNode->_leftChild != NULL);
        }
        
        bool rightChildExists(TreeNode* currentTreeNode){
            return (currentTreeNode->_rightChild != NULL);
        }

        TreeNode* getRootTreeNode(){
            return _rootTreeNode;
        }

        void enterTreeNode(TreeNode* currentTreeNode){
            printf("%d->", currentTreeNode->_value);
            if(leftChildExists(currentTreeNode)){
                enterTreeNode(currentTreeNode->_leftChild);
            }
            if(rightChildExists(currentTreeNode)){
                enterTreeNode(currentTreeNode->_rightChild);
            }
            printf("\n");
        }

        void lengthFirstTraversal(TreeNode* currentTreeNode){
            printf("%d, ", currentTreeNode->_value);
            if(leftChildExists(currentTreeNode)){
                lengthFirstTraversal(currentTreeNode->_leftChild);
            }
            if(rightChildExists(currentTreeNode)){
                lengthFirstTraversal(currentTreeNode->_rightChild);
            }
        }

        void breadthFirstTraversal(){
            // int i = 0;
            while(_traversalQueue.getLength() > 0){
                TreeNode* currentTreeNode = _traversalQueue.DeQueue();
                printf("%d, ", currentTreeNode->_value);
                EnQueueChildren(currentTreeNode);
            }
        }

        void EnQueueChildren(TreeNode* currentTreeNode){

            if(leftChildExists(currentTreeNode)){
                _traversalQueue.EnQueue(currentTreeNode->_leftChild);
            }

            if(rightChildExists(currentTreeNode)){
                _traversalQueue.EnQueue(currentTreeNode->_rightChild);
            }
        }

        bool checkBST(TreeNode* currentNode){
            bool returnValue = 0;
            if(leftChildExists(currentNode)){
                returnValue = checkLeft(currentNode);
                returnValue = returnValue*checkBST(currentNode->_rightChild);
            }
            if(rightChildExists(currentNode)){
                returnValue = returnValue*checkRight(currentNode);
                returnValue = returnValue*checkBST(currentNode->_leftChild);
            }
            if(!(leftChildExists(currentNode) && rightChildExists(currentNode))){
                returnValue = 1;
            }
            return returnValue;
        }

        bool checkLeft(TreeNode* currentNode){
            return currentNode->_leftChild->_value < currentNode->_value;
        }

        bool checkRight(TreeNode* currentNode){
            return currentNode->_rightChild->_value > currentNode->_value;
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
    printf("%d\n", tree1.returnMaximum(tree1.getRootTreeNode()));
    printf("%d\n", tree1.findHeight(tree1.getRootTreeNode()));
    // tree1.enterTreeNode(tree1.getRootTreeNode());
    printf("BST: %d", tree1.checkBST(tree1.getRootTreeNode()));
    tree1.breadthFirstTraversal();
}