#include <iostream>
#include<set>
using namespace std;

// Only Unique value will be stored
// Store value in sorted order (ascending)
// Insertion, deletion, and search operations have logarithmic
// (0(log n)), making them fast for most use cases.
// Generally Implemented using Red-Black Tree(Less rotation as compare to AVL tree) or AVL tree
// We can sort it in descending Order also using greater<type>


int main() {
    set<int> s; // store in increasing order
    // set<int, greater<int>> s; // store in descending order

    // * insertion
    s.insert(10);
    s.insert(20);
    s.insert(110);
    s.insert(210);
    s.insert(10);
    s.insert(210);
    s.insert(110);
    s.insert(20);

    // * Search the element

    // if(s.find(210) != s.end()) // find() return iterator point to that element if present otherwise point -> end()
    //     cout << "Present" << endl;
    // else
    //     cout << "Absent" << endl;

    // if(s.count(200)) // count() return 1  if present otherwise 0
    //     cout << "Present" << endl;
    // else
    //     cout << "Absent" << endl;

    // cout << s.count(1100) << endl;

    // * Traversal
    // cout << "Set element :";
    // for(auto it = s.begin(); it != s.end(); it++){
    //     cout << *it << " ";
    // } cout << endl;

    // cout << "Reverse Order :";
    // for(auto it = s.rbegin(); it != s.rend(); it++){
    //     cout << *it << " ";
    // } cout << endl;




    return 0;
}