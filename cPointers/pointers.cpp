#include <iostream>
#include <stdio.h> 
using namespace std;

int main(){
    cout << endl;

    int a = 1025;
    int* p = &a;
    cout << sizeof(int) << endl;
    cout << p << " and " << *p << endl;

    cout << endl;

    char* p0;
    p0 = (char*)p;
    cout << sizeof(char) << endl;
    cout << p0 << " and " << *p0 << endl;


    cout << endl;
}