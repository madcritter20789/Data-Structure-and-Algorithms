#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
        Node(int data)
        {
            this->data = data;
            left = right = NULL;
        }
};

class BST
{
    private:
        Node *root;
    public:

        //Constructor
        BST()
        {
            root = NULL;
        }

        //Inserting data
        void Insert(int data)
        {
            InsertPrivate(data, root);
        }

        void InsertPrivate(int data, Node *&root)
        {
            if(root == NULL)
            {
                root = new Node(data);
            }
            else if(data < root->data)
            {
                if(root->left != NULL)
                {
                    InsertPrivate(data, root->left);
                }
                else
                {
                    root->left = new Node(data);
                }
            }
            else if(data > root->data)
            {
                if(root->right != NULL)
                {
                    InsertPrivate(data, root->right);
                }
                else
                {
                    root->right = new Node(data);
                }
            }
        }

        //Removing the data from the tree
        void Remove(int data)
        {
            RemovePrivate(data, root);
        }

        void RemovePrivate(int data, Node *&root)
        {
            if(root == NULL)
            {
                return;
            }
            else if(data < root->data)
            {
               RemovePrivate(data, root->left);
            }
            else if(data > root->data)
            {
               RemovePrivate(data, root->right);
            }
            else
            {
                if(root->left == NULL && root->right == NULL)
                {
                    delete root;
                    root = NULL;
                }
                else  if(root->left == NULL)
                {
                    Node *temp = root;
                    root = root->right;
                    delete temp;
                }
                else if(root->right == NULL)
                {
                    Node *temp = root;
                    root = root->left;
                    delete temp;
                }   
                else
                {
                    Node *temp = findMin(root->right);
                    root->data = temp->data;
                    RemovePrivate(temp->data, root->right);
                }    
            }
        }

        Node *findMin(Node *root)
        {
            while(root->left != NULL)
            {
                root = root->left;
            }
            return root;
        }
};

int main()
{
    BST tree;
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(12);
    tree.Insert(15);
    tree.Remove(12);
    return 0;
}