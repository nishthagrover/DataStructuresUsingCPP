
//implementation of Circular Queue Data Structure using array in C++ 
//with functions like enque,deque change, display, isEmpty, isFull, peek and count
//using the concepts of OOPs

#include<iostream>

using namespace std;

class Queue
{
	private:
		int front, rear;
		int arr[5];
	
	public:
		Queue()
		{
			front = -1;
			rear = -1;
			for (int i =0; i<5; i++)
			{
				arr[i] = 0;
						}			
		}
		
		bool isFull()
		{
			if ((rear+1)%5 == front)
				return true;
			else 
				return false;
		}
		
		bool isEmpty()
		{
			if (front == -1 && rear == -1)
				return true;
			else 
				return false;
		}
		
		void enque(int element)
		{
			if (isFull())
				cout<<"Queue is full\n";
			
			else if (isEmpty())
			{
			    front = 0;
				rear = 0;
				arr[rear] = element;
			}
			
			else
			{
				rear = (rear+1)%5;
				arr[rear] = element;
			}
		}
		
		int deque()
		{
			int element;
			if (isEmpty())
			{
				cout<<"Queue is Empty\n";
				return 0;
			}
			else if (front == rear)
			{
				element = arr[front];
				front = -1;
				rear = -1;
				cout<<element<<" was removed from the queue. Now queue is empty\n";
				return element;
			}
				
			else
			{
				element = arr[front];
				front = (front+1)%5;
				cout<<element<<" was removed from the queue.\n";	
				return element;				
			}				
		}
		
		void change(int position, int value)
		{
			
			if (isEmpty())
				cout<<"Queue is Empty\n";
			else if (position < 5 && position > 0)
			{
				arr[position-1] = value;
				cout<<"Value at "<<position<<" changed to "<<value<<endl;
			}
			else 
				cout<< " Invalid position\n";
		}
		
		void display()
		{
			if (isEmpty())
			{
				cout<<"Queue is empty\n";
				return;
			}
			for (int i = 0; i<=5; i++)
			if (arr[i] != 0)
				cout<<arr[i]<<"  ";
			cout<<endl;
		}
		
		int count()
		{
			if (isEmpty())
			{
				cout<<"Queue is empty\n";
				return 0;
			}
			else
			{
				int count = rear - front +1;
				return count;
			}		
		}
		
		void peek(int position)
		{
			if (arr[position-1]==0)
			{
				cout<< "Position is empty\n";
				return;
			}
			cout<<"value at location "<<position<<" = "<<arr[position -1]<<endl;
		}
		
};

int main()
{
	Queue s;
	
	int x=1, element, position, popped;
	
	while(x!=0)
	{
		cout<<"\n\nEnter the serial number to select the suitable Queue operation\n"<<
		  "1. Enqueue\n2. Dequeue \n3. count the number of elements \n"<<
		  "4. display elements \n5. change an element at a given position \n"<<
		  "6. peek at a given position \n0. Exit\n\n";
		cin>>x;
		
		switch(x)
		{
			case 0:
				{
					cout<<"Execution ended. \nThanks!"<<endl;
					break;
				}
			case 1:
				{
					
					cout<<"Enter element to insert in the Queue:"<<endl;
					cin>>element;
					s.enque(element);
					break;
				}
			case 2:
				{
					s.deque();
					break;					
				}
			case 3:
				{
					int count =s.count();
					if (count ==1)
						cout<<"there is "<< count <<" element in the Queue\n";
					if (count>1)
						cout<<"there are "<< count <<" elements in the Queue\n";
					else 
						break;
					break;
				}
			case 4:
				{
					s.display();
					break;
				}
			case 5:
				{
					cout<<"enter position \n";
					cin>>position;
					cout<<"enter value \n";
					cin>>element;
					s.change(position, element);
					break;
				}
			case 6:
				{
					cout<<"enter position \n";
					cin>>position;
					s.peek(position);
					break;
				}
			default:
				{
					cout<<"Invalid input\n";
					break;
				}
		}
		
	}
	return 0;

}
