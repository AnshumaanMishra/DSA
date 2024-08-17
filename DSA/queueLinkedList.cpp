#include <stdio.h>
#include <stdlib.h>

struct Node{
    int _value;
    Node* _nextNodeAddress;
};


class Queue{
    private:
        int* _head;
        int* _tail;
        Node* _firstNode;
        Node* _lastNode;
        Node* _container = new Node;
        int _lengthOfQueue = 0;
        Node* currentNode = new Node;
        Node* prevNode = new Node;

    public:
        Queue(int length, int* localArray){
            for(int i = 0; i < length; i++){
                // currentNode = new Node;
                if(length>0){
                    currentNode = EnQueue(localArray[i]);
                }
                if(i==0){
                    _firstNode = currentNode;
                }
                _lastNode = currentNode;
            }
        }

        Node* EnQueue(int element){
            // Node* currentNode = _lastNode;
            Node* insertedNode = new Node;

            insertedNode->_value = element;
            insertedNode->_nextNodeAddress = NULL;
            if(_lengthOfQueue >= 1){
                _lastNode->_nextNodeAddress = insertedNode;
            }

            if(_lengthOfQueue < 1){
                _firstNode = insertedNode;
            }
            _lastNode = insertedNode;
            _lengthOfQueue ++;
            return insertedNode;
        }

        int DeQueue(){
            Node* tempNode = _firstNode;
            _firstNode = tempNode->_nextNodeAddress;
            _lengthOfQueue -- ;
            return tempNode->_value;
        }

        void printArray(){
            Node* currentNode = _firstNode;
            for(int i = 0; i < _lengthOfQueue; i++){
                printf("%d\n", currentNode->_value);
                currentNode = currentNode->_nextNodeAddress;
            }
        }

        int front(){
            return _firstNode->_value;
        }

        bool isEmpty(){
            return _lengthOfQueue <= 0;
        }


};

int main(){
    // printf("\n");
    int passedArray[] = {};
    int passedSize = sizeof(passedArray)/sizeof(int);

    Queue newQueue = Queue(passedSize, passedArray);
    newQueue.printArray();
    newQueue.EnQueue(10);
    newQueue.printArray();

    return 0;
}
