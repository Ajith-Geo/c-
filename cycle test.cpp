//Floyd's Cycle Detection Algorithm
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

class LinkedList
{
    public:
        Node* head = nullptr;
        Node* tail = nullptr;
        LinkedList(int data)
        {
            Node* newnode = new Node(data);
            head = tail = newnode;
        }

        void append(int data)
        {
            Node* newnode = new Node(data);
            tail->next = newnode;
            tail = newnode;
        }

        void loop()
        {
            tail->next = head;
        }

        int cycle()
        {
            Node* slow = head;
            Node* fast = head;
            while(fast != nullptr && fast->next != nullptr)
            {
                fast = (fast->next)->next;
                slow = slow->next;
                if(fast == slow)
                {
                    return 1;
                }
            }
            return 0;
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
    LinkedList* myll1 = new LinkedList(45);
    myll1->append(65);
    myll1->append(56);
    myll1->append(98);
    myll1->display();
    myll1->loop();
    int flag = myll1->cycle();
    if(flag == 1)
    {
        cout<<"Cycle is present";
    }
    else
    {
        cout<<"No cycle";
    }
    return 0;
}
