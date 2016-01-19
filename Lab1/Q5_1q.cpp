#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	int i,j,k,l,last;
	int input[]={0,1,3,11,2,6,7,2,8,4};
	queue <int> q1;
	q1.push(input[0]);
	for(int i=1;i<10;i++)
	{	last=q1.back();
		if(input[i]>=last)
		{
			q1.push(input[i]);

		}
		else
		{
			while(q1.front()<=input[i])
				{
					q1.push(q1.front());
					q1.pop();
				}
			q1.push(input[i]);
			while(q1.front()>=q1.back())
				{
					q1.push(q1.front());
					q1.pop();
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
	printf("\n");
	return 0;
}