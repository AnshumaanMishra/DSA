#include <iostream>
using namespace std;

class Employee{

    private:
        string Name;
        string Company;
        int Age;

    public:
    
    Employee(string aName, string aCompany, int aAge){
        Name = aName;
        Company = aCompany;
        Age = aAge;
    }

    void introduction(){
        cout << "Name: " << Name << endl;
        cout << "Company: " << Company << endl;
        cout << "Age: " << Age << endl;
    }
};

int main(){
    cout << endl;
    
    
    
    Employee employee1("Hanu", "Google", 18);
    employee1.introduction();
    cout << endl;
    Employee employee2("Jake", "Amazon", 21);
    employee1.introduction();



    cout << endl;
}