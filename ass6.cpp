//============================================================================
// Name        : ass6.cpp
// Author      :Suyash khachne
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node
{
	char a;
	string name;
	struct node *next,*prev;
};
class hall
{
	struct node *start[10];
public:
	void create();
	void traverse();
	void book();
	void cancel();
};
void hall::create()
{
	struct node *temp,*p;
	unsigned short int i=5;
	for (unsigned short int j=0;j<6;j++)
	{
		start[j]=new (struct node);
		start[j]->a='A';
		start[j]->prev=NULL;
		start[j]->next=NULL;
		p=start[j];
		for (i=1; i<6 ;i++)
		{
			temp = new (struct node);
			temp->a='A';
			temp->prev=p;
			temp->next=NULL;
			if (i==1)
				start[j]->next=temp;
			p->next=temp;
			p=p->next;
		}
	}
}
void hall::book()
{
	unsigned short int i,j=0,m=0,n;
	struct node *p;
	cout<<"\n Enter row:";
	cin>>n;
	cout<<"\n Enter Column:";
	cin>>m;
	for (p=start[n-1] ; j<m-1 ; p=p->next)
		j++;
	p->a='B';
}
void hall::cancel()
{
	int i,j=0,m=0,n;
	struct node *p;
	cout<<"\n Enter row:";
	cin>>n;
	cout<<"\n Enter Column:";
	cin>>m;
	for (p=start[n-1] ; j<m-1 ; p=p->next)
		j++;
	p->a='A';

}
void hall::traverse()
{
	int i,j;
	struct node *p;
	for (i=0 ; i<6 ; i++)
	{
		cout<<"\n ";
		for (p=start[i] ; p->next!=NULL ; p=p->next)
			cout<<"\t"<<p->a;
		cout<<"\t"<<p->a;
	}
	
}
int main()
{
	hall x;
	unsigned short int c=0;
	x.create();
	do 
	{
		x.traverse();
		cout<<"\n 1) Book a ticket ";
		cout<<"\n 2) Cancellation of ticket";
		cout<<"\n 3) Exit";
		cin>>c;
		switch(c)
		{
			case 1: 
				x.book();
				cout<<"\b Booked successfully";
				break;
			case 2:
				x.cancel();
				cout<<"\b ticket cancelled successfully";
				break;
		}
	}while (c!=3);
	return 1;
}
