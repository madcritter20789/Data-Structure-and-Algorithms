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

class QueueLinkedList
{
    public:
        Node *front;
        Node *rear;

        //Constructor
        QueueLinkedList()
        {
            front = rear = NULL;
        }

         //Destructor
        ~QueueLinkedList()
        {
            Node *next;
            while(front != NULL)
            {
                next = front->next;
                delete front;
                front = next;
            }
        }
        
        //Inserting data in the Queue
        void Enqueue(int data)
        {   
            Node *n = new Node(data);
            //Check whether queue is empty
            if(rear == NULL)
            {
                rear = front = n;
            }
            else
            {
                rear->next = n;
                rear = n;
            }
        }

        //Removing data from the queue
        int Dequeue()
        {   //Check whether queue is empty
            if(front == NULL)
            {
               cout<<"No of elememnts to dequeue"<<endl;
               return -1;
            }
            Node *temp = front;
            int tempData = front->data;
                if(front == rear)
                {
                    front = rear = NULL;
                }
                else
                {
                    front = front->next;
                }
                delete temp;
                return tempData;
            
        }
    
};

int main()
{

    QueueLinkedList q;
    q.Enqueue(1);
    q.Dequeue();
    q.Dequeue();
    
    return 0;
}