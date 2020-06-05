
// implementation of stack Data Structure in C++ 
//with functions like push, pop, change, display, isEmpty, isFull, peek and count
//using the concepts of OOPs

#include<iostream>

using namespace std;

class Stack
{
	
	private:
		int top;
		
		int arr[10];
	public:
	Stack()
	{
		top = -1;
		for (int i =0; i<10; i++)
		{
			arr[i] = 0; 
		}
				
	}
	
	bool isEmpty()
	{
		if (top == -1) 
			return true;
		else 
			return false;
	} 
	
	bool isFull()
	{
		if (top == (10-1)) 
			return true;
		else 
			return false;
	}
	
	void push(int element)
	{
		if (!isFull())
		{
			top ++;
			arr[top] = element;
			cout<<element<<"inserted"<<endl;
		}
		else
			cout<<"Stack is full"<<endl;
	}
	
	int pop ()
	{
		if (!isEmpty())
		{
			int popped = arr[top];
			arr[top] = 0;
			top --;
			cout<<popped<<"popped"<<endl;
			return popped;
		}
		else
		{
			cout<<"Stack is empty"<<endl;
			return 0;
		}
	}
	
	int count()
	{
		return (top+1);
	}
	
	int peek (int position)
	{
		if (!isEmpty())
			return arr[position-1];
		else
		{
			cout<<"stack is empty"<<endl;
			return 0;
		}
	}
	
	void change (int position, int value)
	{
		arr[position-1] = value;
		cout<<"value at location "<<position<<"position changed to "<<value<<endl;
	}
	
	void display()
	{
		for (int i =0; i<=top; i++)
		{
			cout<<arr[i]<<"  ";
		}
		cout<<"\n";
	}
	
	
		
};

int main()
{
	Stack s;
	
	int x=1, element, position, popped;
	
	while(x!=0)
	{
		cout<<"\nEnter the serial number to select the suitable stack operation\n"<<
		  "1. push element \n2. pop element \n3. count the number of elements \n"<<
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
					
					cout<<"Enter element to push on stack:"<<endl;
					cin>>element;
					s.push(element);
					break;
				}
			case 2:
				{
					popped = s.pop();
					break;					
				}
			case 3:
				{
					int count =s.count();
					if (count)
						cout<<"there are "<< count <<"elements in the stack\n";
					else 
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
					cout<<"value at location"<<position<<" is "<<s.peek(position)<<endl;
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
