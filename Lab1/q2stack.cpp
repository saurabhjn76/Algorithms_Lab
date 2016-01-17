#include<bits/stdc++.h>
using namespace std;
	// stack using 2 queues
int l1=0,l2=0;
int size=10;
int q1[10],q2[10];
bool notEmpty(int i)
{
	if(i==1)
	{
		if(l1==0)
			return false;
		else
			return true;
	}
	else
		if(l2==0)
			return false;
		else
			return true;
}
void enqueue(int i,int element)
{
	if(i==1)
	{
		q1[l1++]=element;

	}
	else 
	{
		q2[l2++]=element;
	}
}
int dequeue(int i)
{
	if(i==1)
	{
		return q1[(l1--)-1];

	}
	else
		return q2[(l2--)-1];
}

void enqueue(int k){
	if(l1<size)
	
	else
		printf("The queue is full\n");
}
void dequeue(){
	if(!notEmpty(1))
		printf("The queue is empty\n");
	else
	{
		while(notEmpty(1))
			push(2,pop(1));
		pop(2);
		while(notEmpty(2))
			push(1,pop(2));

	}

}
void display()
{
	int i;
	for(i=0;i<l1;i++)
	{
		printf("%d-->",q1[i]);
	}
	printf("end\n");

}
int main()
{
	
	int i,j=0,k,l;
	do{
	printf("Choose\n1)Push 2) Pop 3) display 4) exit\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1: printf("Enter the element\n");
				scanf("%d",&k);
				Push(k);
				break;
		case 2: pop();
				break;
		case 3: display();
				break;
		case 4: j=1;
				break;
		default: printf("Wrong choice\n");
	}

	}while(j==0);
	return 0;
}