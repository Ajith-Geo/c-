#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data)
        {
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
};

class BST
{
    public:
        Node* root;
        BST()
        {
            root = nullptr;
        }

        void insert(int data)
        {
            Node* newnode = new Node(data);
            if(root == nullptr)
            {
                cout<<"Inserted as ROOT\n";
                root = newnode;
            }
            else
            {
                Node* temp = root;
                while(true)
                {
                    if(temp->data < newnode->data)
                    {
                        if(temp->right == nullptr)
                        {
                            temp->right = newnode;
                            cout<<"Inserted right\n";
                            break;
                        }
                        else
                        {
                            cout<<"Went right\n";
                            temp = temp->right;
                        } 
                    }

                    else
                    {
                        if(temp->left == nullptr)
                        {
                            cout<<"Inserted left\n";
                            temp->left = newnode;
                            break;
                        }
                        else
                        {
                            cout<<"Went left\n";
                            temp = temp->left;
                        } 
                    }
                }
            }
            cout<<endl;
        }
};

int main()
{
    BST mybst;
    mybst.insert(54);
    mybst.insert(32);
    mybst.insert(65);
    mybst.insert(98);
    mybst.insert(24);
    mybst.insert(89);
    mybst.insert(97);
}
