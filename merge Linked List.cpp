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

        void insert(int index, int data)
        {
            Node* newnode = new Node(data);
            Node* temp = head;
            Node* prev = head;
            int ind = 0;
            while(temp != nullptr)
            {
                if(ind == index)
                {
                    prev->next = newnode;
                    newnode->next = temp;
                    display();
                    break;
                }
                prev = temp;
                temp = temp->next;
                ind++;
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
            cout<<"NULL\n";
            
        }
};

void merge(LinkedList* LL1,LinkedList* LL2)
{
    Node* temp = LL1->head;
    LL1->tail->next = LL2->head;
    LL1->tail = LL2->tail;
    LL2->head = LL1->head;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

int main()
{
    LinkedList* myll1 = new LinkedList(45);
    LinkedList* myll2= new LinkedList(78);
    myll1->append(65);
    myll1->append(56);
    myll1->append(98);
    myll1->display();

    myll2->append(94);
    myll2->append(23);
    myll2->append(49);
    myll2->display();
    merge(myll1,myll2);   
    return 0;
}
