#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data)
        {
            this->data = data;
            next = NULL;
            prev = NULL;
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

    int getSize()
    {
        return size;
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
    
    void prepend(int data)
    {
        //create a node to be inserted
        Node *n = new Node(data);
        //Case 1 : check if leis is empty
        if(header == NULL)
        {
            header = n;
            tail = n;
        }
        //CAse 2 : check is is not empty
        else
        {
            header->prev = n;
            n->next = header;
            header = n;
        }
        size++;
    }

    void append(int data)
    {
        //create a node to be inserted
        Node *n = new Node(data);
        //Case 1 : check if leis is empty
        if(header == NULL)
        {
            header = n;
            tail = n;
        }
        //CAse 2 : check is is not empty
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        size++;
    }
    //Insert at certain postion
    void insertAt(int pos, int data)
    {
        //Case 1 : check for valid position
        if(pos>size+1 || pos<1)
        {
            return;
        }
        //Case 2 : check if insertion at beginning of list
        else if(pos == 1)
        {
            prepend(data);
        }
        //Case 3 : check if insertion at last
        else if(pos == size+1)
        {
            append(data);
        }
        //Case 4 : all other cases
        else if (header != NULL)
        {
            Node *n = new Node(data);
            Node *cur = header;
            for(int i=1; i<pos; i++)
            {
                cur = cur->next;
            }
            cur->prev->next = n;
            n->prev = cur->prev;

            n->next = cur;
            cur->prev = n;

            size++;
        }
    }

    //Printing in reverse
    void toReverseString()
    {
        //Create a temp point
        Node *n = tail;
        //Create a loop that keep executing till pointer is null
        while(n != NULL)
        {
            //print data
            cout<<n->data<<" ";
            //advance pointer to next node
            n = n->prev;
        }
        cout<<endl;
    }
    //Remove First node
    void removeFirst()
    {
        //Case 1 : if there is only one node
        if(header->next == NULL)
        {
            delete header;
            header = NULL;
            tail == NULL;
            size--;
        }
        //Case 2 : if there is more than one node in list
        else if(header != NULL)
        {
            header  = header->next;
            delete header->prev;
            header->prev = NULL;
        }
        size--;
    }

    //Remove Last node
    void removeLast()
    {
        //Case 1 : if there is only one node
        if(header->next == NULL)
        {
            delete header;
            header = NULL;
            tail == NULL;
            size--;
        }
        //Case 2 : if there is more than one node in list
        else if(header != NULL)
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
        }
        size--;
    }

    //Remove at certain node
    void removeAt(int pos)
    {
        //Case 1 : check if position is valid node
        if(pos<1 || pos>size)
        {
            return;
        }
        //Case 2 : check if position is first node
        else if(pos == 1)
        {
            removeFirst();
        }
        //Case 2 : check if position is last node
        else if(pos == size)
        {
            removeLast();
        }
        //Case 4 : check if between first and alst node
        else if(header != NULL)
        {
            Node *cur = header;
            for(int i=1; i<pos; i++)
            {
                cur = cur->next;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
            size--;
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
    list.insertAt(2,3);
    list.toString();
    list.toReverseString();
    list.removeFirst();
    list.toString();
    list.removeLast();
    list.toString();
    list.removeAt(3);
    list.toString();
    return 0;
}