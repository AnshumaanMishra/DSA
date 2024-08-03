#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Node{
    private:
        // Attributes
        int value;
        Node* nextNode;

    public:
    
        // Empty Constructor
        Node(){
            value = 0;
        }

        // Value-and-address Constructor
        Node(int localValue, Node* localAddress){
            value = localValue;
            nextNode = localAddress;
        }

        // Value Setter
        void setValue(int localValue){
            value = localValue;
        }

        // Address Setter
        void setAddress(Node* localAddress){
            nextNode = localAddress;
        }

        // Value Getter
        int getValue(){
            return value;
        }

        // Next Node Address Getter
        Node* getNextNode(){
            return nextNode;
        }
};


class linkedList{
    private:
        Node* firstNode;
        Node* lastNode;
        int sizeOfNode = sizeof(Node);
        int lengthOfList = 0;
        int iter;
        // Node* container = (Node*)malloc(sizeof(Node)); // Container for last node
        Node* container = new Node; // Container for last node
        

    public:

        // Constructor
        linkedList(int sizeOfList, int* localArray){
            if(sizeOfList < 0){
                printf("Invalid Size");
                return;
            }

            if(sizeOfList != 0){
                // Creation of first Node
                firstNode = new Node;
                *firstNode = Node(localArray[0], container);

                Node* previousNode = firstNode; // Current Node
                lengthOfList ++;
                iter = 1;
                for(int i = 1; i < sizeOfList-1; i++){
                    iter = i;
                    
                    Node* currentNode = new Node;
                    // printf("\nCurrent Iteration: %d\n", i);
                    // printf("\nNext Node Location: %p", currentNode);
                    previousNode->setAddress(currentNode);
                    // printf("\nCurrent Node Location: %p\n", (*previousNode).getNextNode());
                    *currentNode = Node(localArray[i], container);
                    previousNode = currentNode;
                    lengthOfList ++;
                }

                if(sizeOfList>1){
                    // Creation of last Node
                    iter++;            
                    // printf("\nLast Element: %d\n ", localArray[iter]);
                    lastNode = new Node;
                    *lastNode = Node(localArray[iter], container);
                    
                    previousNode->setAddress(lastNode);
                    lengthOfList ++;
                }
            }
        }

        void printList(){
            // First Print
            Node* currentNode = firstNode;
            for(int i = 0; i < lengthOfList; i++){
                printf("\n%d: %d\n", i, currentNode->getValue());
                // printf("Next Node Location: %p\n", (*currentNode).getNextNode());
                currentNode = currentNode->getNextNode();
            }
        }

        void freeMemory(){
            Node* currentNode = firstNode;
            for(int i = 0; i < lengthOfList; i++){
                Node* newNode = currentNode->getNextNode();
                free(currentNode);
                currentNode = newNode;
            }
        }

        int getElementByIndex(int index){
            Node* currentNode = firstNode;
            for(int i = 0; i < index; i++){
                currentNode = currentNode->getNextNode();
            }
            return currentNode->getValue();
        }

        int search(int element){
            Node* currentNode = firstNode;
            for(int i = 0; i < lengthOfList; i++){
                if(currentNode->getValue() == element){
                    break;
                }
                currentNode = currentNode->getNextNode();
            }
            return currentNode->getValue();
        }

        void insertElement(int index, int element){
            if(lengthOfList == 0){
                Node* firstNode = new Node;
                *firstNode = Node(1, container);
            }
            else{
                Node* currentNode = firstNode;
                for(int i = 0; i < index-1; i++){
                    currentNode = currentNode->getNextNode();
                }
                // Node* nextNode = (*currentNode).getNextNode();
                Node* insertedNode = new Node;
                (*insertedNode) = Node(element, currentNode->getNextNode());
                currentNode->setAddress(insertedNode);
                lengthOfList++;
            }            
        }

        void insertElement(int element){
            int index = lengthOfList - 1;
            if(lengthOfList == 0){
                Node* firstNode = new Node;
                *firstNode = Node(1, container);
            }
            else{
                Node* currentNode = firstNode;
                for(int i = 0; i < index-1; i++){
                    currentNode = currentNode->getNextNode();
                }
                // Node* nextNode = (*currentNode).getNextNode();
                Node* insertedNode = new Node;
                (*insertedNode) = Node(element, currentNode->getNextNode());
                currentNode->setAddress(insertedNode);
                lengthOfList++;
            }            
        }


    };


int main(){

    int passedArray[] = {};
    int sizeOfPassedArray = sizeof(passedArray)/sizeof(int);
    printf("\n1\n");
    linkedList list1 = linkedList(sizeOfPassedArray, passedArray);
    // list1.printList();
    // printf("Element at Index: 2 is %d", list1.getElementByIndex(2));
    printf("\n1\n");
    list1.insertElement(0, 2);
    printf("\n1\n");
    list1.printList();
}