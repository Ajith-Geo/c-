#include<iostream>
#include<string>
using namespace std;

class Node
{
    public:
        char data;
        Node* next;
        Node(char data)
        {
            this->data = data;
            next = nullptr;
        }
};

class Stack
{
    public:
        Node* top = nullptr;
        Stack(char data)
        {
            Node* newNode = new Node(data);
            top = newNode;
        }
        void push(char data)
        {
            Node* newNode = new Node(data);
            newNode->next = top;
            top = newNode;
        }
        int pop()
        {
            if(top == nullptr)
            {
                return -1;
            }
            Node* temp = top;
            top = top->next;
            temp->next = nullptr;
            return temp->data;
        }
};

int value(char c)
{
    if(c == '{')
    {
        return 1;
    }
    else if(c == '[')
    {
        return 2;
    }
    else if(c == '(')
    {
        return 3;
    }
    else if(c == '}')
    {
        return 4;
    }
    else if(c == ']')
    {
        return 5;
    }
    else if(c == ')')
    {
        return 6;
    }
}

int main()
{
    Stack stack('0');
    int flag = 1;
    string brackets = "{([))}";
    for(int i=0; i<brackets.length(); i++)
    {
        if(value(brackets[i]) < 4)
        {
            stack.push(brackets[i]);
        }
        else
        {
            char data = stack.pop();
            int val = value(brackets[i]);
            if(value(data)+3 == val)
            {
                cout<<"good\n";
            }
            else
            {
                cout<<"bad\n";
                flag = 0;
                break;
            }
        }
    }

    if(flag == 1)
    {
        cout<<"Valid string";
    }
    else
    {
        cout<<"inValid string";
    }
}
