//5) a) Write a routine for changing a sequence of elements in a 
//queue according to a specified input permutation using two temporary queues.
#include <bits/stdc++.h>
using namespace std;

// here the sorting is done using inbuild queue datastructure,in which although the name of function is 
// push and pop but they are behaving as enqueue and dequeue.
int main()
{
	
	int i,j,k,l;
	int input[]={0,1,3,11,2,6,7,2,8,4};
	queue <int> q1;
	queue <int> q2;
	q1.push(input[0]);
	for(int i=1;i<10;i++)
	{
		if(input[i]>=q1.back())
		{
			q1.push(input[i]);

		}
		else
		{
			while(q1.front()<=input[i])
				{
					q2.push(q1.front());
					q1.pop();
				}
			q2.push(input[i]);
			while(q1.empty()!=1)
				{
					q2.push(q1.front());
					q1.pop();
				}
			while(q2.empty()!=1)
				{
					q1.push(q2.front());
					q2.pop();
				}

		}
	}
	i=0;
	while(q1.empty()!=1)
	{
		input[i]=q1.front();
		q1.pop();
		i++;
	}
	printf("The sorted list\n");
	for(int j=0;j<i;j++)
	{

		printf("%d ",input[j]);
		

	}
	return 0;
}
