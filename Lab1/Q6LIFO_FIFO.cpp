#include <bits/stdc++.h>
using namespace std;
 // elements if >8 -- stack
	// else if <=8  --queue
#define SIZE 20
int stack_queue[SIZE];
int length=0;
int pop()
{
	return stack_queue[(+length--)%SIZE];
}
void push(int k)
{
	stack_queue[(+length++)%SIZE]=k;

}
void enqueue(int k)
{
	stack_queue[(+length++)%SIZE]=k;
}
int dequeue()
{
	
	for(int i=0;i<length;i++)
		stack_queue[i]=stack_queue[i+1];
	length--;
}
void insert(int k)
{
	if(length>20)
		printf("Overflow\n");
	else if(length<8 )
		enqueue(k);
	else if(length>=8)
		push(k);
}
void delete_()
{
	if(length<0)
		printf("Underflow\n");
	else if(length<=8 )
		dequeue();
	else if(length>8)
		pop();
}
void display()
{
	int iter=0;
	for(int i=0;i<length;i=(i+1)%SIZE,iter++)
		printf("%d-->",stack_queue[i]);
	printf("\n");
}
int main()
{
	int ch=0,k=0;
	while(ch!=3)
	{
		printf("Menu\n1)Insert  2)Delete    3)exit  4) display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element to be inserted\n");
					scanf("%d",&k);
					insert(k);
					break;
			case 2:
					delete_();
					break;
			case 4: display();
					break;
			case 3: break;
			default: printf("Wrong choice\n");
		}
	}
	return 0;
}