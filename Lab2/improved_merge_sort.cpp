#include <bits/stdc++.h>
using namespace std;
int index_[10];
// program for merge sort(standard-equal-split)
void merge(int *arr,int l ,int m,int r)
{
	int p1=l;
	int p2=m+1;
	int p_out=l;
	int arr_out[100];
	while(p1<m+1 && p2<=r)                       // merging  in ascending order 
	{
		if(arr[p1]<arr[p2])
		{
			arr_out[p_out]=arr[p1];
			p1++;
			p_out++;
		}
		else
		{
			arr_out[p_out]=arr[p2];
			p2++;
			p_out++;

		}
	}
	while(p1<m+1)										// copying from empty array
	{
		arr_out[p_out]=arr[p1];
			p1++;
			p_out++;
	}
	while(p2<=r)											// copying from empty array
	{
		arr_out[p_out]=arr[p2];
			p2++;
			p_out++;
	}
	for(int i=l;i<=r;i++)									// copying to original array
		arr[i]=arr_out[i];
}
void merge_sort(int arr[],int l,int r,int in1,int in2)
{
	if(r==l || in1>=in2)
		return ;
	else
	{
		int m; 
		m=index_[(int)((in1+in2)/2)];
		merge_sort(arr,l,m,in1,(in1+in2)/2);
		merge_sort(arr,m+1,r,(in1+in2)/2+1,in2);
		merge(arr,l,m,r);
	}
}
int main()
{
	int arr[]={2,4,6,83,13,6,7,245,67};
	
	int in=0;
	for(int i=0;i<9-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			index_[in]=i;
			in++;
		}
	}
	merge_sort(arr,0,8,0,in);
	printf("The index of monotonic increasing series:\n");
	for(int i=0;i<in;i++)
		printf("%d ",index_[i] );
	printf("\n");

	printf("The sorted array is :\n");
	for(int i=0;i<9;i++)
		printf("%d ",arr[i] );
	printf("\n");
	return 0;
}