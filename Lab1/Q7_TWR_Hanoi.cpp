//7) Write a routine for transferring the elements of a stack to a second
//stack in the same order, using a third stack as working space. The
//extra restriction is that the relative order of no two elements can be
//reverse of their original on any stack at any stage of the procedure.
#include <bits/stdc++.h>
using namespace std;
int moves=0;

void hanoi(int n,stack<int> *source,int a,stack<int>*spare,int b,stack <int> *destn,int c)
{
	
	if(n==1)
	{
		printf("Move disc 1 from %d to %d\n",a,c);
		destn->push(source->top());
		source->pop();
	}
	else
	{
		hanoi(n-1,source,a,destn,c,spare,b);
		printf("Move %d from %d to %d\n",n,a,c);
		destn->push(source->top());
		source->pop();
		hanoi(n-1,spare,b,source,a,destn,c);
	}
	moves++;
}

int main()
{
	int i,j,k,l,n;
	stack <int> s1;
	stack <int> s2;
	stack <int> s3;

	printf("Enter the number of disc\n");
	scanf("%d",&n);
	printf("Enter the %d elements in descending order:\n",n);
	for(i=0;i<n;i++)
	{
		//scanf("%d",&k);
		s1.push(n-i);
	}
	hanoi(n,&s1,1,&s2,2,&s3,3);
	printf("The total number of moves required:%d\n",moves);
	// whole discs moved to s3 from s1

	return 0;
}	