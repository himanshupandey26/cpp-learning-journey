#include <iostream>
#include <list>
using namespace std;

void displayListElement(list<int> &lst){
    list<int> :: iterator it;
    for (it = lst.begin(); it != lst.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    // list<int> list1;    // empty list of size 0
    // list<int> list2(7);  // empty list of size 7, 0 0 0 0 0 0 0 

    // // Inserting
    // list1.push_back(1);
    // list1.push_back(2);
    // list1.push_back(3);
    // list1.push_back(4);
    // list1.push_back(5); 

    // // Printing
    // list<int> :: iterator itr;
    // itr = list1.begin();

    // cout << *itr << " "; // 1
    // itr++; // ->2
    // cout << *itr << " "; // 2
    // itr++; // ->3
    // cout << *itr << " "; // 3
    // itr++; // ->4
    // cout << *itr << " "; // 4
    // itr++; // ->5
    // cout << *itr << " "; // 5
    // itr++; // -> end
    // cout << endl;
    // cout << *itr << " ";
    // itr--;
    // cout << *itr << " ";
    // itr--;
    // cout << *itr << " ";
    // itr--;
    // cout << *itr << " ";
    // itr--;
    // cout << *itr << " ";
    // itr--;

    // displayListElement(list1);

    // list<int> :: iterator it2;
    // it2 = list2.begin();
    // *it2 = 1;
    // it2++;
    // *it2 = 2;
    // it2++;
    // *it2 = 3;
    // it2++;
    // *it2 = 4;
    // it2++;
    // *it2 = 5;
    // it2++;
    // *it2 = 6;
    // it2++;
    // displayListElement(list2);


    list<int> l1 = {1,22,3,24,5};
    list<int> l2 = {12, 32, 4, 23, 24,1};

    displayListElement(l1); // 1 22 3 24 5 
    // l1.reverse(); // main list me hi kar rha hai
    // displayListElement(l1);
    // l1.sort();
    // displayListElement(l1);

    displayListElement(l2); // 12 32 4 23 24 1 

    // l1.merge(l2); // dono ke element ko compare kar ke chota put kar rha hai final me
    // displayListElement(l1);

    // l1.sort();
    // l2.sort();
    // l1.merge(l2);
    // displayListElement(l1); // 1 1 3 4 5 12 22 23 24 24 32 
    // l1.remove(1);  // remove all occurence of element
    // displayListElement(l1); // 3 4 5 12 22 23 24 24 32 

    // displayListElement(l2); // 12 32 4 23 24 1 
    l2.pop_front();
    displayListElement(l2); //  32 4 23 24 1 
    l2.pop_back();
    displayListElement(l2); // 32 4 23 24
    cout << "First element: " << l2.front() << endl;  // 32
    cout << "Last element: " << l2.back() << endl;  // 24
    cout << "Size: " << l2.size() << endl;  // 4
    // l2.clear();  // Sab delete karo
    if (l2.empty()) {
        cout << "List empty!" << endl;
    } else {
        cout << "List has elements!" << endl;
    }

    return 0;
}