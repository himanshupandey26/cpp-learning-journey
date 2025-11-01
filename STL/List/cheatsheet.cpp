#include <iostream>
#include<list>

using namespace std;

int main() {
    
    // 🚀 LIST CHEAT SHEET — EXAM/CODING ROUND KE LIYE

    list <int> l;                    // Declare
    l.push_back(x);                 // Add at end
    l.push_front(x);                // Add at start
    l.pop_back();                   // Remove last
    l.pop_front();                  // Remove first
    l.remove(x);                    // Remove all x
    l.sort();                       // Sort ascending
    l.reverse();                    // Reverse order
    l.size();                       // Get size
    l.empty();                      // Check empty

    // Iterator traversal
    for(auto it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }

    // Range-based (easiest!)
    for(int x : l) {
        cout << x << " ";
    }

    return 0;
}