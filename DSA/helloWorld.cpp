#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

string convertOperator(char operatorCharacter){
            if(operatorCharacter == '+'){
                return "+";
            }
            else if(operatorCharacter == '-'){
                return "-";
            }
            else if(operatorCharacter == '*'){
                return "*";
            }
            else if(operatorCharacter == '/'){
                return "/";
            }
            else if(operatorCharacter == '^'){
                return "^";
            }
            return "";
        }

int main(){
    string element = "12345";
    element.append(" " + convertOperator('+'));
    cout << element << endl;
    return 0;
}