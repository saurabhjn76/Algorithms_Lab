// stack using 2 queues
# include <bits/stdc++.h>
using namespace std;
	
int l1=0,l2=0;
int size=10;
int q1[10],q2[10];
int frontA=0,frontB=0,rearA=-1,rearB=-1;
bool notEmpty(int i)
{
	if(i==1)
	{
		if(frontA>rearA)
			return false;
		else
			return true;
	}
	else
		if(frontB>rearB)
			return false;
		else
			return true;
}
void enqueue(int i,int element)
{
	if(i==1)
	{
		q1[++rearA%size]=element;

	}
	else 
	{
		q2[++rearB%size]=element;
	}
}
int dequeue(int i)
{
	if(i==1)
	{
		return q1[frontA++%size];

	}
	else
		return q2[frontB++%size];
}

void push(int k){
	if(rearA-frontA<size)
	{
		if(rearA==-1)
			enqueue(1,k);
		else
		{
			while(notEmpty(1))
			{
				enqueue(2,dequeue(1));

			}
			enqueue(1,k);
			while(notEmpty(2))
			{
				enqueue(1,dequeue(2));

			}

		}
	}
	else
		printf("The queue is full\n");
}
void pop(){
	if(!notEmpty(1))
		printf("The stack is empty\n");
	else
	{
		dequeue(1);

	}

}
void display()
{
	int i;
	for(i=frontA;i<=rearA;i++)
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
				push(k);
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