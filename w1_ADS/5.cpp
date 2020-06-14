#include <iostream>
using namespace std;

const short int link_array_size = 30; 

struct link 
{
	int array [link_array_size]; 
	short int capacity; 
	link* next; 
	link () 
	{
		capacity = link_array_size;
	}
	void link_push (int n)
	{
		capacity--;
		array [capacity] = n; 
	}
	int link_pop ()
	{
		capacity++;
		return array[capacity-1]; 
	}
};

struct stack 
{
	link* head; 
	int s; 
	stack (link* h = NULL) 
	{
		head = h;
		s = 0;
	}
	void add_link()
	{
		link* a = new link;
		a->next = head;
		head = a;
	}
	void destroy_link() 
	{
		link * a = head;
		head = a->next;
		delete a;
	}
	void push (int n)
	{
		if ((head == NULL)||(head->capacity == 0))
		{
			add_link();
		}
		head->link_push(n);
		s++;
	}
	int pop ()
	{
		if (s>0)
		{
			int n = (head->link_pop());
			if (head->capacity == link_array_size)
			{
			destroy_link();
			}
			s--;
			return n;
		}
		else
		{
			throw 0;
		}
	}
	int back()
	{
		if (s>0)
		{
			return head->array[head->capacity];
		}
		else
		{
			throw 0;
		}
	}
	int size()
	{
		return s;
	}
	void clear()
	{
		while (head!=NULL)
		{
			destroy_link();
		}
		s = 0;
	}
};

int main()
{
	string s;
	stack Q;
	while (cin>>s)
	{
		if (s == "push")
		{
			int n;
			cin>>n;
			Q.push(n);
			cout<<"ok"<<endl;
		}
		if (s == "pop")
		{
			try
			{
				cout<<Q.pop()<<endl;
			}
			catch (int e)
			{
				cout<<"error"<<endl;
			}
		}
		if (s == "back")
		{
			try
			{
				cout<<Q.back()<<endl;
			}
			catch (int e)
			{
				cout<<"error"<<endl;
			}
		}
		if (s == "size")
		{
			cout<<Q.size()<<endl;
		}
		if (s == "clear")
		{
			Q.clear();
			cout<<"ok"<<endl;
		}
		if (s == "exit")
		{
			cout<<"bye"<<endl;
			break;
		}
	}
	return 0;
}