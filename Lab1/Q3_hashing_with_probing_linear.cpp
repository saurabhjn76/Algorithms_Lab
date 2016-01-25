//3) Implement hashing by probing using different schemes.
// Take care of deleted slots and differentiate them from slots never occupied.
#include <bits/stdc++.h>
 using namespace std;
 int size=20;
 int table[20]={0};
 int linear_probing(int ke,int i){
 	//hash function=ke%size;
 	//new hash function
 	int new_index=((ke%size)+i)%size;  // linear probing
 	return new_index;

 }
 void insert( int table[],int ke,int i)
 {
 	int prob_i=0,new_index;
 	new_index=linear_probing(ke,prob_i);
 	while(table[new_index]!=0 && table[new_index]!=-1)       // collision found
 		new_index=linear_probing(ke,++prob_i);
 	table[new_index]=i;
 	
 }
 void deleted(int table[],int ke,int val)
 {
 	int prob_i=0;
 	int new_index=linear_probing(ke,prob_i);
 	while(table[new_index]!=val)
 		{
 			new_index=linear_probing(ke,++prob_i);
 			if(table[new_index]!=0)            // never filled block found
 				{
 					printf("Value not found\n");
 					break;
 				}

 		}
 	if(table[new_index]==val)	
 		{
 			table[new_index]=-1; 
 			printf("The %d sucessfully deleted\n",val);    // differentiated from the never filled up
 		}
 	
 }
 void dipslay(int table[])
 {
 	int i;
 	for(i=0;i<size;i++)
 	{
 		if(table[i]!=0 && table[i]!=-1)
 			printf("%d-> %d\n",i,table[i]);
 	}

 }
 void search(int table[],int ke,int val){
 	int prob_i=0;
 	int new_index=linear_probing(ke,prob_i);
 	while(table[new_index]!=val)
 		{
 			new_index=linear_probing(ke,++prob_i);
 			if(table[new_index]!=0)            // never filled block found
 				{
 					printf("Value not found\n");
 					break;
 				}

 		}
 	if(table[new_index]==val)	
 		{
 			printf("The %d found\n",val);   
 		}

 }
 int main()
 { 
 	int ke,i,j=0,k,c;
 	while(j==0)
	{
 
	 	printf("Choose the operation\n1)insert 2)delete 3)dipslay 4) search 5) exit\n");
 		scanf("%d",&c);
 		switch(c)
 		{
 		case 1:printf("Insert the key and element\n");
 				scanf("%d %d",&ke,&i);
 				insert(table,ke,i);
 				break;
 		case 2:printf("delete the element,enter key,enter value \n");
 			   scanf("%d %d",&ke,&i);
 			   deleted(table,ke,i);
 			   break;
 		case 3:printf("The table looks like--->\n");
 				dipslay(table);
 				break;
 		case 5: j=1;
 				break;
 		case 4:printf("search the element,enter key,enter value\n");
 			   scanf("%d %d",&ke,&i);
 			   search(table,ke,i);
 			   break;
 		default:printf("Wrong Choice\n");
 		}
 	}

 	return 0;
 }