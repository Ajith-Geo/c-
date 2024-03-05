#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(int data)
        {
            this->data = data;
            next = nullptr;
        }
};

class Stack
{
    public:
        Node* head;
        Node* tail;
        Stack()
        {
            head = nullptr;
        }

        void push(int data)
        {
            Node* newnode = new Node(data);
            if(head == nullptr)
            {
                head = newnode;
            }
            else
            {
                newnode->next = head;
                head = newnode;
            }
        }

        void pop()
        {
            if(head != nullptr)
            {
                Node* temp = head;
                head = head->next;
                delete temp;
                display();
            }
            else
            {
                cout<<"cannot pop\n";
            }
            
            
        }
        void display()
        {
            Node* temp = head;
            while(temp != nullptr)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"\n";
        }
};

int main()
{
    Stack* myll1 = new Stack();
    myll1->push(65);
    myll1->push(56);
    myll1->push(98);
    myll1->display();
    myll1->pop();
    myll1->pop();
    myll1->pop();
    myll1->pop();
    
}
