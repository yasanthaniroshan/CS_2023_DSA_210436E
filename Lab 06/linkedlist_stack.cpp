#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <stdexcept>

using namespace std;

class node
{
private:
    int nodeData;

public:
    node *next;
    node(int data)
    {
        next = nullptr;
        nodeData = data;
    }

    int data()
    {
        return nodeData;
    }
};

class linked_Stack
{
private:
    int length;
    int size;

public:
    node *head;
    linked_Stack(int size)
    {
        this->head = nullptr;
        this->length = 0;
        this->size = size;
    }

    int push(int data)
    {
        if (length == size)
        {
            throw overflow_error("Stack is full");
        }
        else
        {
            node *new_node = new node(data);
            if (head == nullptr)
            {
                head = new_node;
                length += 1;
                return data;
            }
            else
            {
                new_node->next = head;
                head = new_node;
                length += 1;
                return data;
            }
        }
    }

    int pop()
    {
        if (head == nullptr)
        {
            throw underflow_error("Stack is empty");
        }
        else if (head->next == nullptr)
        {
            node *current_node = head;
            head = nullptr;
            length -= 1;
            return current_node->data();
        }
        else
        {
            node *current_node = head;
            head = current_node->next;
            length -= 1;
            return current_node->data();
        }
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }

    bool isFull()
    {
        return (length == size);
    }
    int StackTop()
    {
        if (this->head != nullptr)
        {
            return this->head->data();
        }
        else
        {
            throw underflow_error("Stack is empty");
        }
    }
    int Display()
    {
        if (this->head == nullptr)
        {
            throw underflow_error("Stack is empty");
        }
        else
        {
            node *current_node = this->head;
            while (current_node->next != nullptr)
            {
                cout << "Element : " << current_node->data() << endl;
                current_node = current_node->next;
            }
            cout << "Last Element : " << current_node->data() << endl;
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
        linked_Stack Stack(stack_size);

        

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
        std::cerr << '\n' <<"Error : " << e.what() << '\n';
        exit(1);
    }

    auto ending_of_stack = chrono::high_resolution_clock::now();
    auto duration_of_stack = chrono::duration_cast<chrono::microseconds>(ending_of_stack - starting_of_stack);
    cout << "Time taken by stack : " << duration_of_stack.count() << " microseconds" << endl;
}