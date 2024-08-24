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
                printf("%d\n", currentQueueNode->_value->_value);
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
        Queue _deleteQueue;
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

        TreeNode* deleteByValue(int element, TreeNode* currentTreeNode){
            if(leftChildExists(currentTreeNode) && currentTreeNode->_leftChild->_value == element){
                deleteQueueTraversal(currentTreeNode);
                // _deleteQueue.DeQueue();
                TreeNode* currentChild = currentTreeNode->_leftChild;
                currentTreeNode->_leftChild = NULL;
                printf("After Deletion: ");
                breadthFirstTraversal();
                insertQueueElements(_deleteQueue);
                return currentChild;
            }
            else if(rightChildExists(currentTreeNode) && currentTreeNode->_rightChild->_value == element){
                deleteQueueTraversal(currentTreeNode->_rightChild);
                _deleteQueue.DeQueue();
                // _deleteQueue.DeQueue();
                TreeNode* currentChild = currentTreeNode->_rightChild;
                currentTreeNode->_rightChild = NULL;
                printf("After Deletion: ");
                breadthFirstTraversal();
                printf("\n");
                _deleteQueue.printQueue();
                insertQueueElements(_deleteQueue);
                return currentChild;
            }
            else if((element < currentTreeNode->_value) && leftChildExists(currentTreeNode)){
                return deleteByValue(element, currentTreeNode->_leftChild);
            }
            else if((element > currentTreeNode->_value) && rightChildExists(currentTreeNode)){
                return deleteByValue(element, currentTreeNode->_rightChild);
            }
            
            return NULL;
        }

        void efficientDelete(int element){
            TreeNode* currentNode = search(element, getRootTreeNode());
            TreeNode* minNode = returnMinimum(currentNode->_rightChild);
            currentNode->_value = minNode->_value;
            currentNode->_rightChild = minNode->_rightChild;
            currentNode->_leftChild = minNode->_leftChild;
            minNode->_parentTreeNode->_leftChild=NULL;
        }

        void insertQueueElements(Queue localQueue){
            while(!localQueue.isEmpty()){
                int removedValue = localQueue.DeQueue()->_value;
                insert(removedValue);
                printf("Removed value: %d, After Insertion: ", removedValue);
                lengthFirstTraversal(getRootTreeNode());
                printf("\n");
            }
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

        TreeNode* returnMinimum(TreeNode* currentTreeNode){
            if(leftChildExists(currentTreeNode)){
                return returnMinimum(currentTreeNode->_leftChild);
            }
            return currentTreeNode;
        }

        TreeNode* returnMaximum(TreeNode* currentTreeNode){
            if(rightChildExists(currentTreeNode)){
                return returnMaximum(currentTreeNode->_rightChild);
            }
            return currentTreeNode;
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
            else if((element == currentTreeNode->_value)){
                return;
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
        
        TreeNode* search(int element, TreeNode* currentTreeNode){
            if(currentTreeNode->_value == element){
                return currentTreeNode;
            }
            else if((element < currentTreeNode->_value) && leftChildExists(currentTreeNode)){
                return search(element, currentTreeNode->_leftChild);
            }
            else if((element > currentTreeNode->_value) && rightChildExists(currentTreeNode)){
                return search(element, currentTreeNode->_rightChild);
            }
            return NULL;
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

        void deleteQueueTraversal(TreeNode* currentTreeNode){
            _deleteQueue.EnQueue(currentTreeNode);
            if(leftChildExists(currentTreeNode)){
                deleteQueueTraversal(currentTreeNode->_leftChild);
            }
            if(rightChildExists(currentTreeNode)){
                deleteQueueTraversal(currentTreeNode->_rightChild);
            }
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
            while(_traversalQueue.getLength() > 0){
                TreeNode* currentTreeNode = _traversalQueue.DeQueue();
                printf("%d, ", currentTreeNode->_value);
                EnQueueChildren(currentTreeNode, _traversalQueue);
            }
            // printf("IsEmpty %d", _traversalQueue.isEmpty());
            if(_traversalQueue.isEmpty()){
                _traversalQueue.EnQueue(_rootTreeNode);
                printf("\n");
            }
        }

        void EnQueueChildren(TreeNode* currentTreeNode, Queue localQueue){
            if(leftChildExists(currentTreeNode)){
                localQueue.EnQueue(currentTreeNode->_leftChild);
            }
            if(rightChildExists(currentTreeNode)){
                localQueue.EnQueue(currentTreeNode->_rightChild);
            }
        }

        bool checkBST(TreeNode* currentNode){
            // printf("\nCurrentNode: %p\nCurrentValue: %d, \nRightChild: %p, \nLeftChild: %p\n", currentNode, currentNode->_value, currentNode->_rightChild, currentNode->_leftChild);
            bool returnValue;
            if(leftChildExists(currentNode)){
                returnValue = checkLeft(currentNode);
                // printf("\nLeftNode Checked: %d", returnValue);
                returnValue = returnValue*checkBST(currentNode->_leftChild);
                // printf("\nLeftTree Checked: %d", returnValue);
            }
            if(rightChildExists(currentNode)){
                returnValue = returnValue*checkRight(currentNode);
                // printf("\nRightNode Checked: %d", returnValue);
                returnValue = returnValue*checkBST(currentNode->_rightChild);
                // printf("\nRightTree Checked: %d", returnValue);
            }
            if(!leftChildExists(currentNode) && !rightChildExists(currentNode)){
                returnValue = 1;
            }
            // printf("\n");
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
    // printf("%d\n", tree1.returnMaximum(tree1.getRootTreeNode()));
    printf("%d\n", tree1.findHeight(tree1.getRootTreeNode()));
    // tree1.enterTreeNode(tree1.getRootTreeNode());
    // tree1.breadthFirstTraversal();
    printf("\n");
    tree1.lengthFirstTraversal(tree1.getRootTreeNode());
    printf("\n");
    // tree1.deleteByValue(3, tree1.getRootTreeNode());
    tree1.efficientDelete(3);

    printf("BST: %d\n", tree1.checkBST(tree1.getRootTreeNode()));
    tree1.lengthFirstTraversal(tree1.getRootTreeNode());
    // printf("\n");
}