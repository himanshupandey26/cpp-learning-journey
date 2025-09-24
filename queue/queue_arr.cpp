#include <iostream>
using namespace std;

class Queue{
    public:
    int front, rear, size;
    int* arr;
    
    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
};

int main() {


    return 0;
}