#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#include <list>

struct Channel{
    string Name;
    int SubCount;

    Channel(string name, int subCount){
        Name = name;
        SubCount = subCount;
    }
};


bool operator==(Channel channel1, Channel channel2){
    return ((channel1.Name == channel2.Name) && (channel1.SubCount==channel2.SubCount));
}

// Return ostream object if multiple operands required
ostream& operator<<(ostream& COUT, Channel& channel){
    COUT << "Name: " << channel.Name << endl;
    COUT << "Subs: " << channel.SubCount << endl;
    return COUT;
}

struct MyCollection{
    list<Channel> myChannels;

    void operator+=(Channel channel){
        this->myChannels.push_back(channel);
    }

    void operator-=(Channel channel){
        this->myChannels.remove(channel);
    }
};

ostream& operator<<(ostream& COUT, MyCollection myCollection){
    for(Channel channel : myCollection.myChannels){
        COUT << channel << endl;
    }
    return COUT;
}


int main(){
    printf("\n");
    
    Channel channel1("The AM Show", 1000000);
    Channel channel2("The AM Show2", 800000);
    // cout << channel1;

    MyCollection myCollection;
    myCollection += channel1;
    myCollection += channel2;
    myCollection -= channel2;    

    cout << myCollection;
    // operator<<(cout, channel2);

    printf("\n");
    return 0;
}