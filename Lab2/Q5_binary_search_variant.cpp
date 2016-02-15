#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,j,k=-2;
	printf("Enter the number of elements\n");
	scanf("%d",&n);

	int a[n+1];
	a[0]=-99;         //  assumed as negative infinity
	printf("Enter the elements\n");
	for(i=1;i<=n;i++)
			{
				scanf("%d",&a[i]);
				if(a[i-1]>a[i] && k==-2)
					k=i;
			}
			a[0]=a[n];
			//printf("%d\n",k );
	printf("Enter the element to be searched\n");
	scanf("%d",&m);
	int low=k;
	int high=k+n-1;
	int mid;
	
	while(high>=low)
	{
		 mid=(low + high)/2;
		if(a[mid%n]>m)
		{
			high=mid-1;
			printf("high=%d\n",high );
		}
		else if(a[mid%n]<m)
		{
			low=mid+1;
			printf("Low=%d\n",low );
		}
		else
		{
			if(mid!=n)
			printf("Element found!!!! \n Rank of the element is %d\n",mid%n);
		else 
			printf("Element found!!!! \n Rank of the element is %d\n",n);
			break;
		}
	}
	if(a[mid%n]!=m)
		printf("Search failed!!\n");
	


	





	return 0;
}