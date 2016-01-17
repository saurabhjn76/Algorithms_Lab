#include <bits/stdc++.h>
 using namespace std;
 int size=10;
 int table[10]={0};
 void insert( int table[],int ke,int i)
 {
 	table[ke]=i;
 	
 }
 void deleted(int table[],int k)
 {
 	table[k]=0;
 	
 }
 void dipslay(int table[])
 {
 	int i;
 	for(i=0;i<size;i++)
 	{
 		if(table[i]!=0)
 			printf("%d-> %d\n",i,table[i]);
 	}

 }
 void search(int table[],int k){
 	if(table[k]!=0)
 	printf("%d\n",table[k] );
 	else
 		printf("The data is not present in this key\n");

 }
 int main()
 { 
 	int ke,i,j=0,k,c;
 	while(j==0)
	{
 
	 	printf("Choose the operation\n1)insert 2)delete 3)dipslay 4) search4) exit\n");
 		scanf("%d",&c);
 		switch(c)
 		{
 		case 1:printf("Insert the key and element\n");
 				scanf("%d %d",&ke,&i);
 				insert(table,ke,i);
 				break;
 		case 2:printf("delete the element,enter key \n");
 			   scanf("%d",&i);
 			   deleted(table,i);
 			   break;
 		case 3:printf("The table looks like--->\n");
 				dipslay(table);
 				break;
 		case 5: j=1;
 				break;
 		case 4:printf("search the element,enter key \n");
 			   scanf("%d",&i);
 			   search(table,i);
 			   break;
 		default:printf("Wrong Choice\n");
 		}
 	}

 	return 0;
 }