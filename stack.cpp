#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 1000;
struct Stack{
    int stack[MAX+1];
    int top;
};

void initialization(Stack &stack){
    stack.top = 0;
}

bool isEmpty(Stack stack){
    if (stack.top == 0) return true;
    return false;
}

bool isFull(Stack stack){
    if (stack.top == MAX) return true;
    return false;
}

bool peek(Stack stack, int &value){
    if (isEmpty(stack)) return true;
    value = stack.stack[stack.top];
    return true;
}

bool push(Stack &stack, int value){
    if (isFull(stack)) return false;
    stack.stack[++stack.top] = value;
    return true;
}

bool pop(Stack &stack, int &value){
    if (isEmpty(stack)) return false;
    value = stack.stack[stack.top--];
}

bool print(Stack stack){
    int result;
    while (!isEmpty(stack))
    {
        pop(stack, result);
        cout << result << " ";
    }
    cout << endl; 
}

int main(){
    int n, value;
    Stack s;
    ifstream infile("input.txt");
    // Enter data to stack
    infile >> n;
    for(int i = 0; i < n; i++){
        infile >> value;
        push(s,value);
    }
    infile.close();
    //Peek
    peek(s, value);
    cout << "peek value: " << value << endl;
    // Print
    print(s);
    cout << endl;
    return 0;
}