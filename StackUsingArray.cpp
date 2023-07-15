#include <iostream>
using namespace std;

class StackArray
{
    public:
        int size;
        int *stackarr;
        int top;

    public:
        //Constructor
        StackArray(int size)
        {
            this->size = size;
            stackarr = new int[size];
            top = -1;
        }
        //destructor
        ~StackArray()
        {
            delete[] stackarr;
        }
        //Resizing the full array
        void Resize()
        {
            int tempSize = size*2;
            int *temp = new int[tempSize];
            for(int i=0;i<size;i++)
            {
                temp[i] = stackarr[i];
            }
            delete[] stackarr;
            stackarr = temp;
            size = tempSize;
        }
        //Pushing the data in stack
        void push(int data)
        {
            if(top == size-1)
            {
                Resize();
            }
            stackarr[++top] = data;
        }
        //Popping ouyt the data from array
        int Pop()
        {
            if(top == -0)
            {
                cout<<"Stack is empty."<<endl;
                return -1;
            }
            return stackarr[top--];
        }
         //Printing top data
        int peek()
        {
            if (top < 0) 
            {
                cout << "Stack is Empty";
                return 0;
            }
            else 
            {
                int x = stackarr[top];
                return x;
            }
        }
    
};

int main()
{
    StackArray s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.Pop() << " Popped from stack\n";
    
    //print top element of stack after popping
    cout << "Top element is : " << s.peek() << endl;
    
    return 0;
}