/* 
Borillo, Raphael Jedidiah R. | BCS32 | 202230704
Problem 3:
To manage high-volume package sorting, you need to implement a recursive algorithm for dividing and processing packages efficiently. 
You decide to model this process using the Tower of Hanoi problem, where the packages need to be moved from one location to another using a buffer.

Write a recursive function to solve the Tower of Hanoi problem for N packages (discs). 
The goal is to move all packages from the source to the destination using the buffer, following the rules:

Only one package can be moved at a time.
A larger package cannot be placed on top of a smaller package.
*/
#include <iostream>
using namespace std;

int toh_process(int n, string start, string end, string mid) {
    // Base case: If only one package, move directly to target
    if (n == 1) {
        cout << "Move pack 1 from " << start << " to " << end << endl;
        return 1;  // We've made one move
    }
    int moves = toh_process(n - 1, start, mid, end);
    cout << "Move pack " << n << " from " << start << " to " << end << endl;
    moves += 1;
    moves += toh_process(n - 1, mid, end, start);
    return moves;
}

int main() {
    int packnum;
    cout << "Enter number of packages you would like to move (recommended number is below 10, as higher numbers may impact performance): ";
    cin >> packnum;

    cout << "Calculating number of movements needed for packages..." << endl;
    cout << "\nProcess:" << endl;

    int movestotal = toh_process(packnum, "Port 1 (source)", "Port 3 (destination)", "Port 2 (buffer)");
    cout << "Total moves needed: " << movestotal << endl;
    return 0;
}
