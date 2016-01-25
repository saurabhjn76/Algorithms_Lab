//2) Implement hashing with chaining.
#include <bits/stdc++.h> 
using namespace std;


# define SIZE 10
typedef struct hash_table{
	int value;
	struct hash_table *next;
}hash_table;
hash_table table[SIZE];
hash_table* makeNode(int k)
{
	hash_table *node=(hash_table*)calloc(1,sizeof(hash_table));
	node->value=k;
	node->next=NULL;
	return node;
}
void insert(int k)
{
	int key=k%SIZE;                    // hash function
	if(table[key].value==-1)
		table[key].value=k;
	else                                    // collidion found
	{
		hash_table *temp=&(table[key]);

		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=makeNode(k);
	}

}

void display()
{
	hash_table * temp;
	for(int i=0;i<SIZE;i++)
	{
		if(table[i].value!=-1)
		{
			for(temp=&(table[i]);temp!=NULL;temp=temp->next)
				printf("%d-->",temp->value);
			printf("end\n");
		}
	}

}
int search(int k)
{
	hash_table * temp;
	int key=k%SIZE;                   // hash function
	if(table[key].value!=-1)
		{
			for(temp=&(table[key]);temp!=NULL ;temp=temp->next)
				if(temp->value==k)
				{
					printf("%d-->Found\n",temp->value);
					return 1;
					break;
				}
		}
	else
		{
			printf("The element is not present\n");
			return 0;
		}
	if(temp==NULL)
		{
			printf("The element is not present\n");
			return 0;
		}
}
int deleted(int k)
{
	hash_table * temp,*prev;
	int key=k%SIZE;                                 // hash function
	if(table[key].value!=-1)
		{
			for(temp=&(table[key]);temp!=NULL ;temp=temp->next)
			{
				
					if(temp->value==k)
				{
					prev->next=temp->next;
					free(temp);
					return 1;
					break;
				}
				prev=temp;
			}
		}
	else
		{
			printf("The element is not present\n");
			return 0;
		}
	if(temp==NULL)
		{
			printf("The element is not present\n");
			return 0;
		}

}
int main()
{
	int i,j,k,ch=0;
	for(i=0;i<SIZE;i++)
		table[i].value=-1;
	while(ch!=5)
	{
		printf("Choose\n1)insert 2) search 3) delete 4)display 5)EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element\n");
					scanf("%d",&k);
					insert(k);
					break;
			case 2: printf("Enter the element\n");
					scanf("%d",&k);
					search(k);
					break;
			case 3: printf("Enter the element\n");
					scanf("%d",&k);
					deleted(k);
					break;
			case 4: display();
					break;
		}
	}

	return 0;
}