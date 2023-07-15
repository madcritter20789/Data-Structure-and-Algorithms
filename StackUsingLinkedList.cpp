#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            next = NULL;
        }
};
class StackLinkedList
{
    private:
        Node *top;

    public:
        //Constructor
        StackLinkedList(int size)
        {
            top = NULL;
        }
        //destructor
        ~StackLinkedList()
        {
            Node *next;
            while (top != NULL)
            {
                next = top->next;
                delete top;
                top = next;
            } 
        }
        //Resizing the full array
        void Resize()
        {
            
        }
        //Pushing the data in stack
        void Push(int data)
        {
            Node *n = new Node(data);
            if(top == NULL)
            {
                top = n;
            }
            else
            {
                n->next = top;
                top = n;
            }
        }
        //Popping ouyt the data from array
        int Pop()
        {
            if(top == NULL)
            {
                cout<<"Stack is empty."<<endl;
                return -1;
            }
            else
            {
                int tempData = top->data;
                Node *temp = top;
                top = top->next;
                delete temp;
                return tempData;
            }
        }
        //Printing top data
        int peek()
        {
            if (top != NULL)
            {
                return top->data;
            }  
            else
            {
                exit(1);
            }
        }
        //Printing the stack
        void display()
        {
            Node* temp;
    
            // Check for stack underflow
            if (top == NULL) {
                cout << "\nStack Underflow";
                exit(1);
            }
            else {
                temp = top;
                while (temp != NULL) {
                    // Print node data
                    cout << temp->data;   
                    // Assign temp link to temp
                    temp = temp->next;
                    if (temp != NULL)
                    {    cout << " -> ";    }
                }
            }
        }
    
};

int main()
{
    StackLinkedList s(5);
    s.Push(10);
    s.Push(20);
    s.Push(30);
    cout << s.Pop() << " Popped from stack\n";
    s.display();
    cout<<endl;
    //print top element of stack after popping
    cout << "Top element is : " << s.peek() << endl;
    
    return 0;
}