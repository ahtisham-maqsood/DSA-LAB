#include <iostream>
using namespace std;

const int SIZE = 5;

class Stack {
    int arr[SIZE];
    int top = -1;
public:
    void push(int val) {
        if (top == SIZE - 1) 
        { 
            cout << "Overflow\n";
        }
        else{ 
            arr[++top] = val;}
    }
    void pop() {
        if (top == -1) {
            cout << "Underflow\n";}
        else{
            top--;}
    }
    void display() {
        for (int i = top; i >= 0; i--){
             cout << arr[i] << " ";
            }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(14); s.push(23); s.push(33);
    s.display();
    s.pop();
    s.display();
}
