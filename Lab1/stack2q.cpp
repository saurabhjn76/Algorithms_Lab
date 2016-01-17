//Ques4) Write a code for implementing a stack, a queue, and a queue simulated by two stacks 
//and a stack simulated by two queues, all using prespecified size arrays. 
//You need to implement the push, pop, enqueue, dequeue operations and error checks.
#include <bits/stdc++.h>
using namespace std;
// queue using 2 stacks
int lengthA=0,lengthB=0;
int size=10;
int stack1[10],stack2[10];
bool notEmpty(int i)
{
	if(i==1)
	{
		if(lengthA==0)
			return false;
		else
			return true;
	}
	else
		if(lengthB==0)
			return false;
		else
			return true;
}
void push(int i,int element)
{
	if(i==1)
	{
		stack1[lengthA++]=element;

	}
	else 
	{
		stack2[lengthB++]=element;
	}
}
int pop(int i)
{
	if(i==1)
	{
		return stack1[(lengthA--)-1];

	}
	else
		return stack2[(lengthB--)-1];
}

void enqueue(int k){
	if(lengthA<size)
	push(1,k);
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
	for(i=0;i<lengthA;i++)
	{
		printf("%d-->",stack1[i]);
	}
	printf("end\n");

}
int main()
{
	
	int i,j=0,k,l;
	do{
	printf("Choose\n1)enqueue 2) dequeue 3) display 4) exit\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1: printf("Enter the element\n");
				scanf("%d",&k);
				enqueue(k);
				break;
		case 2: dequeue();
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