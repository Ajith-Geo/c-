#include<iostream>
#include<queue>
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

        void BFS()
        {
            Node* temp = root;
            queue<Node*> myqueue;
            myqueue.push(root);
            while(!myqueue.empty())
            {
                Node* popped = myqueue.front();
                myqueue.pop();

                cout<<popped->data<<" ";
                if(popped->left != nullptr)
                {
                    myqueue.push(popped->left);
                }

                if(popped->right != nullptr)
                {
                    myqueue.push(popped->right);
                }

            }
            cout<<endl;    
        }

        void PreOrder(Node* temp)
        {
            
            cout<<temp->data<<" ";
            if(temp->left != nullptr)
            {
                PreOrder(temp->left);
            }
            if(temp->right != nullptr)
            {
                PreOrder(temp->right);
            }
        }

        void InOrder(Node* temp)
        {
            
            if(temp->left != nullptr)
            {
                InOrder(temp->left);
            }
            
            cout<<temp->data<<" ";

            if(temp->right != nullptr)
            {
                InOrder(temp->right);
            }
        }

        void PostOrder(Node* temp)
        {
            
            if(temp->left != nullptr)
            {
                PostOrder(temp->left);
            }

            if(temp->right != nullptr)
            {
                PostOrder(temp->right);
            }

            cout<<temp->data<<" ";
        }
};

int main()
{
    BST mybst;
    mybst.insert(47);
    mybst.insert(21);
    mybst.insert(76);
    mybst.insert(18);
    mybst.insert(27);
    mybst.insert(52);
    mybst.insert(82);
    mybst.BFS();
    mybst.PreOrder(mybst.root);
    cout<<endl;
    mybst.InOrder(mybst.root);
    cout<<endl;
    mybst.PostOrder(mybst.root);
}
