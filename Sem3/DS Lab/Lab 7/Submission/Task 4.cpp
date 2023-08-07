#include<iostream>
using namespace std;
  
class Queue
{
    int rear, front;
    int size;
    int *arr;
  
public:
    
    Queue(int s)
    {
       front = rear = -1;
       size = s;
       arr = new int[s];
    }

bool QueueCapacity()
{
	if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))
	return true;
	
	return false;
}  

bool isEmpty()
{
	if(front==-1)
	return true;
	
	return false;
}

void ADDMemeber(int value)
{
    if (QueueCapacity())
    {
        cout<<"\nQueue is Full";
        return;
    }
  
    else if (front == -1)
    {
        front = rear = 0;
        arr[rear] = value;
    }
  
    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }
  
    else
    {
        rear++;
        arr[rear] = value;
    }
}
  
// Function to delete element from Circular Queue
int RemoveMember()
{
    if (front == -1)
    {
        cout<<"\nQueue is Empty";
        return INT_MIN;
    }
  
    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;
  
    return data;
}
  
// Function displaying
void displayQueue()
{
    if (isEmpty())
    {
        cout<<"\nQueue is Empty";
        return;
    }
    cout<<"\nElements in Circular Queue are: ";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout<<arr[i]<<endl;
           
    }
    else
    {
        for (int i = front; i < size; i++)
             cout<<arr[i]<<endl;

        for (int i = 0; i <= rear; i++)
             cout<<arr[i]<<endl;
      
    }
}
};
  
/* Driver of the program */
int main()
{
    Queue q(4);
  
    // Inserting elements in Circular Queue
    q.ADDMemeber(10);
    q.ADDMemeber(22);
    q.ADDMemeber(30);
    q.ADDMemeber(-6);
  
    // Display elements present in Circular Queue
    q.displayQueue();
  
    // Deleting elements from Circular Queue
    cout<<"\nDeleted value ="<<q.RemoveMember();
    q.displayQueue();
 
  
    return 0;
}
