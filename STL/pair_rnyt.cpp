#include <iostream>
// #include<bits/stdc++.h>
#include <utility>  // pair lives here
using namespace std;

int main() {

    // implement with the help of class

    // pair declaration
    pair<string,int>p1;

    // insertion of values

    p1 = make_pair("Himanshu", 70);

    p1.first = "Harsh";
    p1.second = 80;
    
    p1 = {"Sonu",40};
    
    
    // cout << p1.first << " " << p1.second << endl;

    // * for three variable -> name, age, marks
    pair<string,pair<int,int>> p3 = {"Rohan",{20,78}};
    pair<pair<string,int>,int> p4 = {{"Rohan",20},88};

    cout << p3.first<< " " << p3.second.first << " " << p3.second.second << endl;
    
    cout << p4.first.first<< " " << p4.first.second << " " << p4.second << endl;

    // cout << p3 << endl; // error

    return 0;
}