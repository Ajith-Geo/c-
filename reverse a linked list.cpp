#include<iostream>
using namespace std;

class Node
{
    public:
        Node* next;
        int data;
        Node(int data)
        {
            this->data = data;
            next = nullptr;
        }
};

class LL
{
    public:
        Node* head;
        Node* tail;
        LL()
        {
            head = tail = nullptr;
        }

        void append(int data)
        {
            Node* newnode = new Node(data);
            if(head == nullptr && tail == nullptr)
            {
                head = tail = newnode;
            }
            else
            {
                Node* temp = head;
                while(temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newnode;
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
            cout<<endl;
        }

        void reverse()
        {
            Node* prev = nullptr;
            Node* current = head;
            Node* nxt = nullptr;

            while (current != nullptr)
            {
                nxt = current->next;
                current->next = prev;
                prev = current;
                current = nxt;
            }

            head = prev;
        }

};

int main()
{
    LL myll;
    myll.append(34);
    myll.append(65);
    myll.append(78);
    myll.append(965);
    myll.append(321);
    myll.display();
    myll.reverse();
    myll.display();
}
