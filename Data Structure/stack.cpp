#include <bits/stdc++.h>

using namespace std;

class Stack
{
    int *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[this->size];
        top = -1;
    }

    void push(int value)
    {
        if (this->top == this->size - 1)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            this->top++;
            this->arr[this->top] = value;
        }
    }

    void deleteTop()
    {
        if (this->top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            this->top--;
        }
    }

    int topElement()
    {
        if (this->top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return this->arr[this->top];
    }

    bool isEmpty()
    {
        if (this->top == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if (this->top == this->size - 1)
            return true;
        return false;
    }
};

int main()
{
    Stack myStack(5);
    myStack.push(2);
    cout << myStack.isEmpty() << endl;
    cout << myStack.isFull() << endl;
    cout << myStack.topElement() << endl;

    return 0;
}
