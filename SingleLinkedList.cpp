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

class  LinkedList
{
private:
    Node *header;
    Node *tail;
    int size;

    public:
    LinkedList()
    {
        header = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }
    
    //Deconstructor
    ~LinkedList()
    {
        Node *next;
        while (header != NULL)
        {
            next = header->next;
            delete header;
            header = next;
        }       
    }

    //Append Node in linked list 
    void append(int data)
    {
        //Create new Node
        Node *n = new Node(data);
        //Case 1 : Empty list
        if(header == NULL)
        {
            header = n;
            tail = n;
        }
        //Case 2 : List is not empty
        else
        {
            tail->next = n;
            tail = n;
        }
        //Increment size amount
        size++;
    }

    //Prepend Node in linked list 
    void prepend(int data)
    {
        //Create new Node
        Node *n = new Node(data);
        //Case 1 : Empty list
        if(header == NULL)
        {
            header = n;
            tail = n;
        }
        //Case 2 : List is not empty
        else
        {
            Node *temp = header;
            header = n;
            n->next = temp;
        }
        //Increment size amount
        size++;
    }
    //Printing tha data
    void toString()
    {
        //Create a tempoprary pointer that pints to first node
        Node *temp = header;
        //create a loop that stop when pointer is null
        while(temp != NULL)
        {
            //print data
            cout<<temp->data<<" ";
            //advance poionter to next node
            temp = temp->next;
        }    
        cout<<endl;
    }

    //Remove FIrst node
    void removeFirst()
    {
        //Case 1 : empty list
        if(header != NULL)
        {
            Node *temp = header;
            header = header->next;
            delete temp;
            size--;
        }
        //Case 2 : not empty list
    }

    //Remove Last node
    void removeLast()
    {
        //Case 1 : empty list
        //Case 2 :1 node
        if(header->next == NULL)
        {
            removeFirst();
        }
        //Case 3 : More than one
        else if(header != NULL)
        {
            Node *cur = header;
            Node *prev;
            while(cur->next != NULL)
            {
                prev = cur;
                cur = cur->next;
            }
            tail = prev;
            prev->next = NULL;
            delete cur;
            size--;
        }
    }

    //Remove at certain position
    void remaoveAt(int pos)
    {
        //Case : 1 check for valid position
        if(pos>size || pos<1)
        {
            return;
        }
        //CAse 2 : check if positin is forst one
        else if(pos == 1)
        {
            removeFirst();
        }
        //Case 2 : check if insertion at beginning of list
        else if(pos == size)
        {
            removeLast();
        }
        //Case 4 : all other cases
        else if (header != NULL)
        {
            Node *prev;
            Node *cur = header;
            for(int i=1; i<pos; i++)
            {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            delete cur;
            size--;
        }
    }

    //Insert at certain postion
    void insertAt(int pos, int data)
    {
        //Case 1 : check for valid position
        if(pos>size || pos<1)
        {
            return;
        }
        //Case 2 : check if insertion at beginning of list
        else if(pos == 1)
        {
            prepend(data);
        }
        //Case 3 : check if insertion at last
        else if(pos == size)
        {
            append(data);
        }
        //Case 4 : all other cases
        else if (header != NULL)
        {
            Node *n = new Node(data);
            Node *prev;
            Node *cur = header;
            for(int i=1; i<pos; i++)
            {
                prev = cur;
                cur = cur->next;
            }
            prev->next = n;
            n->next = cur;
            size++;
        }
    }
};

int main()
{
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.prepend(10);
    list.toString();
    list.removeFirst();
    list.toString();
    list.removeLast();
    list.toString();
    list.remaoveAt(2);
    list.toString();
    list.insertAt(2,2);
    list.toString();
    return 0;
}