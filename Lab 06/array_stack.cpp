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
        if (top + 1 == stack_size)
        {
            throw overflow_error("Stack is full");
        }
        else
        {
            top = top + 1;
            array[top] = data;
            return data;
        }
    }

    int pop()
    {
        if (top == -1)
        {
            throw underflow_error("Stack is empty");
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
            throw underflow_error("Stack is empty");
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
        if (top == -1)
        {
            throw underflow_error("Stack is empty");
        }
        for (int i = top; i > -1; i--)
        {
            cout << "Element " << i << " : " << array[i] << endl;
        }
    }
};

int main()
{

    auto starting_of_stack = chrono::high_resolution_clock::now();

    int stack_size;
    cout << "Enter the size of stack : ";
    cin >> stack_size;  


    try
    {

        arr_Stack Stack(stack_size);

        for (int i = 0; i < (stack_size/3)*2; i++)
        {
            cout << "Pushing element : " << Stack.push(rand() % 100) << endl;
        }

        Stack.Display();

        for (int i = 0; i < (stack_size/3); i++)
        {
            cout << "Popping element : " << Stack.pop() << endl;
        }

        Stack.Display();

        for (int i = 0; i < (stack_size/3); i++)
        {
            cout << "Pushing element : " << Stack.push(rand() % 100) << endl;
        }

        Stack.Display();
    }
    catch (const std::exception &e)
    {
        std::cerr<<'\n'<< "Error : " << e.what() << '\n';
        exit(1);
    }

    auto ending_of_stack = chrono::high_resolution_clock::now();
    auto duration_of_stack = chrono::duration_cast<chrono::microseconds>(ending_of_stack - starting_of_stack);
    cout << "Time taken by stack : " << duration_of_stack.count() << " microseconds" << endl;
}