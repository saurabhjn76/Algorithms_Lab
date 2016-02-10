#include <bits/stdc++.h>
using namespace std;
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
void merge_sort(int arr[],int l,int r)
{
	if(r==l)
		return ;
	else
	{
		int m=(r+l)/2;
		merge_sort(arr,l,m);
		merge_sort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
int main()
{
	int arr[]={2,4,6,83,13,6,7,245,67};
	merge_sort(arr,0,8);
	printf("The sorted array is :\n");
	for(int i=0;i<9;i++)
		printf("%d ",arr[i] );
	printf("\n");
	return 0;
}