#include <iostream>
using namespace std;

class List{
    private:
        int mainList[0] = {};
    public:

        List(){
            int mainList[0] = {};
        }
        List(int aList[]){
            int mainList[sizeof(aList)];
            copy(aList, aList+sizeof(aList), mainList);
        }

        void printList(){
            for(int i = 0; i < sizeof(mainList); i++){
                cout << mainList[i] << endl;
            }
            cout << "Done" << endl;
        }
};

int main(){
    int tempList[4] = {1,2,3,4};
    List list1(tempList);
    list1.printList();
}