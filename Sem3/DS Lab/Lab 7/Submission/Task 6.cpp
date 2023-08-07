#include <iostream>
using namespace std;
class Node 
{
public:
   int priority;
   int info;
	Node *next;
};
class Priority_Queue {
   private:
      Node *front;
   public:
      Priority_Queue() 
      {
         front = NULL;
      }
      void insert(int i, int p) 
	  {
         Node *temp, *temp2;
         temp= new Node;
         temp->info=i;
         temp->priority=p;
         if (front == NULL || p > front->priority) 
		 {
            temp->next=front;
            front=temp;
         } 
		 else 
		 {
            temp2=front;
            while (temp2->next != NULL && temp2->next->priority >= p)
               temp2 = temp2->next;
               
               temp->next = temp2->next;
               temp2->next = temp;
         }
      }
      void del() 
	  {
        Node *temp;
        if(front == NULL) 
        cout<<"Queue Underflow\n";
        
		else 
		 {
            temp = front;
            cout<<"Deleted item is: "<<temp->info<<endl;
            front = front->next;
            free(temp);
         }
      }
      void show() 
	    {
		
		Node *ptr;
        ptr = front;
        if (front == NULL)
        cout<<"Queue is empty\n";
        else 
		{
            cout<<"Queue: ";
            while(ptr != NULL) 
			{
               cout<<ptr->info<<"  ";
               ptr=ptr->next;
            }
         }
      }
};
int main() 
{
   Priority_Queue pq;
	
	int n,x;
	cout<<"Enter number of blocks: ";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cout<<"Enter size of blocks at "<<i+1<<": ";
		cin>>x;
		pq.insert(x,x);
	}
	pq.show();
	pq.del();
	pq.show();
}
