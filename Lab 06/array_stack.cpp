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

int main()
{

    auto starting_of_stack = chrono::high_resolution_clock::now();

    arr_Stack Stack(20);

    for(int i = 0; i < 10; i++)
    {
        cout << "Pushing element : "<< Stack.push(rand() %100) << endl;
    }

    Stack.Display();

    for(int i = 0; i < 5; i++)
    {
        cout << "Popping element : " << Stack.pop() << endl;
    }

    Stack.Display();

    for(int i = 0; i < 5; i++)
    {
        cout << "Pushing element : "<< Stack.push(rand() %100) << endl;
    }

    Stack.Display();

    auto ending_of_stack = chrono::high_resolution_clock::now();
    auto duration_of_stack = chrono::duration_cast<chrono::microseconds>(ending_of_stack - starting_of_stack);
    auto time_taken_iterative = chrono::duration_cast<chrono::duration<double>>(ending_of_stack - starting_of_stack).count();

    cout << "Time taken by stack : " << duration_of_stack.count() << " microseconds" << endl;
    cout << "time taken for iterative is : " << fixed << setprecision(20)<< time_taken_iterative << " microseconds"<< endl;
 
}