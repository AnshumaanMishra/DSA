or(int i = 0; i < index-1; i++){
                    currentNode = (*currentNode).getNextNode();
                }
                // Node* nextNode = (*currentNode).getNextNode();
                Node* insertedNode = new Node;
                (*insertedNode) = Node(element, (*currentNode).getNextNode());
                (*currentNode).setAddress(insertedNode);
                l