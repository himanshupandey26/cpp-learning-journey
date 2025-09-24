#include <iostream>
#include<queue>
using namespace std;

int main() {
    cout << endl << endl;
    // creation
    queue<int> q; 

    // insertion
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);

    // front 
    cout << "first element : " << q.front() << endl;

    // deletion
    q.pop();

    cout << "first element : " << q.front() << endl;

    // size
    cout << "Size : " << q.size() << endl;

    if (q.empty()){
        cout << "q is empty" << endl;
    } else {
        cout << "q is not empty" << endl;
    }

    q.pop();
    q.pop();
    q.pop();

    if (q.empty()){
        cout << "q is empty" << endl;
    } else {
        cout << "q is not empty" << endl;
    }
    return 0;
}