#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *ROOT=NULL;

void insert();
void search();
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void delete(int);

void main()
{
	int opt,x;
	do
	{
	printf("Choose operation :\n1.INSERT\n2.Inorder_traversal\n3.PreOrder_Traversal\n4.PostOrder_Traversal\n5.search \n6.Delete\n");
	scanf("%d",&opt);
		switch(opt)
			{
	  		case 1:insert();
		                break;
		          case 2:inorder(ROOT);
		                break;
		  	 case 3:preorder(ROOT);
		                break;
			case 4:postorder(ROOT);
		                break;
			case 5:search();
		                break;
			case 6:printf("Enter Data to be deleted\n");
				scanf("%d",&x);
				delete(x);
		                break;


			}
	}
	while(opt!=7);
}

void insert()
{
struct node *ne,*ptr,*ptr1;
int x;
ne=(struct node *)malloc(sizeof(struct node));
	if (ne == NULL)
		{
		printf("Insufficient Memory") ;
		return;
		}

	printf("Enter Data to insert\n");
	scanf("%d",&x);
	ne->left=NULL;
	ne->right=NULL;
	ne->data=x;
	if(ROOT == NULL)
		{
			ROOT = ne;
			return;
		}
	ptr =ROOT;
	while(ptr!=NULL)
	{
		if(x==ptr->data)
			{
			printf("Data already exist....\n") ;
			return;
			}
		if(x > ptr->data)
			{
			ptr1=ptr;
			ptr= ptr->right;
			}
		else
			{
			ptr1=ptr;
			ptr= ptr->left;
			}

	}
	if(ptr==NULL)
	{
		if(x > ptr1->data)
			{
			ptr1->right=ne;
			}
		else
			{
			ptr1->left=ne;
			}
	}
}

void search()
{
int x;
struct node *ptr=ROOT;
printf("\nEnter the data to search: ");
scanf("%d",&x);
while(ptr!=NULL)
	{
		if(ptr->data==x)
			{
			printf("Data is present....\n") ;
			break;
			}
		if(x > ptr->data)
			{
			ptr= ptr->right;
			}
		else
		{
		ptr= ptr->left;
		}
	}
if(ptr==NULL)
	printf("\n Data not present....\n");
}


void inorder(struct node *ptr)
{

	if(ptr != NULL)
	{
	inorder(ptr->left);
	printf("%d " ,ptr->data);
	inorder(ptr->right);
	}
}

void preorder(struct node *ptr)
{
if(ptr != NULL)
	{
	printf("%d " ,ptr->data);
	preorder(ptr->left);
	preorder(ptr->right);
	}

}

void postorder(struct node *ptr)
{
    if(ptr!=NULL)
	{
	postorder(ptr->left);
	postorder(ptr->right);
	printf("%d " ,ptr->data);
	}
}


void delete(int x)
{
struct node *ne,*ptr,*parent,*p;
int dat;
	if (ROOT == NULL)
		{
		printf("\n Tree is Empty \n") ;
		return;
		}
	parent= NULL;
	ptr=ROOT;
	while(ptr!=NULL)
	{
		if(ptr->data==x)
			break;
		parent=ptr;
		if(x > ptr->data)
			ptr= ptr->right;
		else
			ptr= ptr->left;
	}
		if(ptr==NULL)
			{
			printf("\n Data not present....\n");
			return;
			}
if(ptr->right==NULL&&ptr->left==NULL)
	{
	if (parent==NULL)
		ROOT=NULL;
	else if (parent->right==ptr)
		parent->right=NULL;
	else
		parent->left=NULL;
		printf("Element deleted");

	free(ptr);
	return;
	}

if(ptr->right!=NULL&&ptr->left!=NULL)
	{
	p=ptr->right;
	while(p->left!=NULL)
	{
	p=p->left;
	}
	dat=p->data;
	delete(p->data);
	ptr->data=dat;
	return;
	}

if (parent==NULL)
	{
	if (ptr->right==NULL)
		ROOT=ptr->left;
	else
		ROOT=ptr->right;
	}

else
	{
	if (parent->right==ptr)
		{
		if (ptr->right==NULL)
			parent->right=ptr->left;
		else
			parent->right=ptr->right;
		}
	else
		{
		if (ptr->left==NULL)
			parent->left= ptr->right;
		else
			parent->left=ptr->left;

		}
	}
printf("Element deleted");
free(ptr);
return;
}
















