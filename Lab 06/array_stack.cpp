#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <stdexcept>

using namespace std;

class arr_Stack
{
private:
    int top;
    int stack_size;
    int array[];
    

public:
    arr_Stack(int size)
    {
        this->array[size];
        this->top = -1;
        this->stack_size = size;
    }

    int push(int data)
    {
        top = top + 1;
        array[top] = data;
        return data;
    }

    int pop()
    {
        if (top == -1)
        {
            return -1;
        }
        else
        {
            int current_top = top;
            top -= 1;
            return array[current_top];
        }
    }
    int StackTop()
    {
        if (top == -1)
        {
            return -1;
        }
        else
        {
            return array[top];
        }
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return (top + 1 == stack_size);
    }
    void Display()
    {
        for(int i = top ; i > -1; i--)
        {
            cout << "Element " << i << " : " << array[i]<< endl;
        }
    }
};

