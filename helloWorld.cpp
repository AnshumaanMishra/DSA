#include <iostream>
using namespace std;

class AbstractEmployee{
    virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee{

    private:
        
        string Company;
        int Age;
    protected:
        string Name;
    public:
        void setName(string name){
            Name=name;
        }
        string getName(){
            return Name;
        }
        void setCompany(string company){
            Company=company;
        }
        string getCompany(){
            return Company;
        }
        void setAge(int age){
            Age=age;
        }
        int getAge(){
            return Age;
        }


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
        void AskForPromotion(){
            if (Age>30){
                cout << Name << " got promoted!!" << endl;
            }
            else{
                cout << Name << " not promoted!!" << endl;
            }
        }
        virtual void Work(){
            cout << Name << " is checking eMail, task backlog, performing tasks..." << endl;
        }


};

class Developer: public Employee{
    public:
        string favProgrammingLanguage;
        Developer(string aName, string aCompany, int aAge, string favLang):Employee(aName, aCompany, aAge){
            favProgrammingLanguage=favLang;
        }

        void fixBug(){
            cout << Name << " fixed bug using " << favProgrammingLanguage << endl;
        }
        void Work(){
            cout << Name << " is writing "<<favProgrammingLanguage<< " code" << endl;
        }
};

class Teacher: public Employee{
    public: 
        string Subject;

        void prepareLesson(){
            cout << Name << " is preparing " << Subject << " lesson." << endl;
        }

        Teacher(string aName, string aCompany, int aAge, string subject): Employee(aName, aCompany, aAge){
            Subject = subject;
        }

        void Work(){
            cout << Name << " is teaching "<<Subject << endl;
        }
};

int main(){
    cout << endl;
    


    Developer d("Ace", "YT", 25, "C++");
    Teacher t("Beatrice", "Cool", 35, "Geo");  
    // d.Work();
    // t.Work(); 
    Employee * e1 = &d;
    Employee * e2 = &t;

    e1->Work();
    e2->Work();



    cout << endl;
}