// b) Write a routine for changing a sequence of elements in a stack according to a specified permutation
// using two temporary stacks.
#include <bits/stdc++.h>
using namespace std;


int main()
{
	int i,j,k,l;
	int input[]={10,1,3,11,2,6,7,2,8,4};
	stack <int> s1;
	stack <int> s2;
	stack <int> s3;
	for(i=9;i>=0;i--)
		{
			s3.push(input[i]);
			
		}

	s1.push(s3.top());
	s3.pop();
	for(int i=1;i<10;i++)
	{
		if(s1.top()>=s3.top())
			{
				s1.push(s3.top());
				//printf("%d: %d\n",i,s3.top());
				s3.pop();
			}
		else
		{
			while(s1.top()<s3.top())
			{

				s2.push(s1.top());
				//printf("%d: %d(1--->2)\n",i,s1.top());
				s1.pop();
				if(s1.empty()==1)
					break;

			}
		
			if(s3.empty()!=1)
			{

				s1.push(s3.top());
				//printf("%d: %d(3-->1)\n",i,s3.top());
				s3.pop();
			}
			while(s2.empty()!=1)
				{s1.push(s2.top());
					//printf("%d: %d(2-->1)\n",i,s2.top());
				s2.pop();
			}

		}

		
	}

	for(int i=0;s1.empty()!=1;i++)
		{
			printf("%d-->", s1.top());
			s1.pop();
		}
		printf("\n");


	return 0;
}