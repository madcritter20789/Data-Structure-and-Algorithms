#include <iostream>
using namespace std;

class QueueArray
{
    public:
        int front,
            rear,
            numOfElements,
            size;
        int *queueArr;

        void Resize()
        {
            int tempSize = size*2;
            int *tempArr = new int[tempSize];
            for(int i=0; i<size; i++)
            {
                tempArr[i] == queueArr[(front + i)%size];
            }
            delete []queueArr;
            queueArr = tempArr;
            front = 0;
            rear = size-1;
            size = tempSize;

        }
        //Constructor
        QueueArray(int data)
        {
            front = rear = -1;
            this->size = size;
            queueArr = new int[size];
            numOfElements = 0;
        }
        //Inserting data in the Queue
        void Enqueue(int data)
        {   //Check whether queue is empty
            if(numOfElements == size)
            {
                Resize();
            }
            if(front == -1 && rear == -1)
            {
                front = rear = 0;
            }
            else
            {
                rear = (rear +1)%size;
            }
            queueArr[rear] = data;
            numOfElements++;
        }

        //Removing data from the queue
        int Dequeue()
        {   //Check whether queue is empty
            if(numOfElements == 0)
            {
               cout<<"No of elememnts to dequeue"<<endl;
               return -1;
            }
            else
            {
                int temp = queueArr[front];
                if(front == rear)
                {
                    rear = front = -1;
                }
                else
                {
                    front = (front + 1)%size;
                }
                 numOfElements--;
                return temp;
            }
        }
    
};

int main()
{

    QueueArray q(5);
    q.Enqueue(1);
    q.Dequeue();
    q.Dequeue();
    
    return 0;
}