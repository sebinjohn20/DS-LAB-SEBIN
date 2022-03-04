#include<stdio.h>
#include<stdlib.h>

void frst_insert();
void lst_insert();
void display();
void search();
void frst_delete();
void lst_delete();
void insert_pos();
void delete_pos();

struct node
{
int data;
struct node *next;
struct node *left;
struct node *right;
};
struct node *head;

void main()
{
	int opt;
	do
	{
	printf("Choose operation :\n1.Insert an element at FIRST\n2.Insert an element at LAST\n3.Display\n4.SEARCH\n5.Delete First Element....\n6.Delete Last Element....\n7.Insert an item at position\n8.Delete an item at Position\n");
	scanf("%d",&opt);
		switch(opt)
			{
	  		case 1:
		                frst_insert();
		                break;
		          case 2:
		                lst_insert();
		                break;
		  	 case 3:
		                display();
		                break;
			case 4:
		                search();
		                break;
			case 5:
		                frst_delete();
		                break;
			case 6:
		                lst_delete();
		                break;
			case 7:
		                insert_pos();
		                break;
			case 8:
		                delete_pos();
		                break;
			}
	}
	while(opt!=0);
}

void frst_insert()
{
	struct node *ne;
	int x;
	printf("Enter the element to INSERT\n");
	scanf("%d",&x);
	ne=(struct node *)malloc(sizeof(struct node));
	if (ne == NULL)
		{
		printf("Insufficient Memory") ;
		return;
		}
	ne->data=x;
	ne->left=NULL;
	ne->right=NULL;
	if(head == NULL)
		{
		head=ne;
		}
	else
		{
		ne->right=head;
		head->left=ne;
		head=ne;
		}
}
void lst_insert()
{
	struct node *ne;
	struct node *ptr;
	int x;
	printf("Enter the element to INSERT\n");
	scanf("%d",&x);
	ne=(struct node *)malloc(sizeof(struct node));
	if (ne == NULL)
		{
		printf("Insufficient Memory") ;
		return;
		}
	ne->data=x;
	ne->left=NULL;
	ne->right=NULL;
	if(head == NULL)
		{
		head=ne;
		}
	else
		{
		ptr=head;
		while(ptr->right!=NULL)
			{
			ptr=ptr->right;
			}
		ptr->right=ne;
		ne->left=ptr;
		}
}
void display()
{
struct node *ptr;
if (head == NULL)
	{
	printf("LInked List is Empty") ;
	return;
	}
ptr=head;
while(ptr!=NULL)
		{
		printf("%d \t",ptr->data);
		ptr=ptr->right;
		}
printf("\n");
}



void search()
{
	struct node *ptr;
	int x;
	printf("Enter the element to search\n");
	scanf("%d",&x);
	if (head == NULL)
		{
		printf("LInked List is Empty") ;
		return;
		}
	else
	{
	ptr=head;
	while(ptr!=NULL)
			{
			if(ptr->data==x)
			{
				printf("Element Found");
				printf("\n");
				break;
			}
			ptr=ptr->right;
			}
			if(ptr==NULL)
				{
				printf("Element Not Found");
				printf("\n");
				}	
	}

}



void frst_delete()
{
	struct node *ptr;
	if (head == NULL)
		{
		printf("LInked List is Empty") ;
		return;
		}
	ptr = head;
	head = head->right;
	if (head == NULL)
		{
		head->left=NULL;
		}
	
	free(ptr);
}


void lst_delete()
{
struct node *ptr;
struct node *prev;
if (head == NULL)
		{
		printf("LInked List is Empty") ;
		return;
		}
if (head->right == NULL)
		{
		free(head);
		head = NULL;
		}
ptr = head;
while(ptr->right!=NULL)
		{
		ptr=ptr->right;
		}
prev=ptr->left;
prev->right=NULL;
free(ptr);
			
}

void insert_pos()
{
	struct node *ne;
	struct node *ptr,*ptr1;
	int x,key;
	printf("Enter the element to INSERT\n");
	scanf("%d",&x);
	printf("Enter the position where you want to insert item: ");
        scanf("%d", &key);
	ne=(struct node *)malloc(sizeof(struct node));
	if (ne == NULL)
		{
		printf("Insufficient Memory") ;
		return;
		}
	ne->data=x;
	ne->left=NULL;
	ne->right=NULL;
	if(head == NULL)
	{
		head=ne;
		return;
	}
	ptr = head;
	while(ptr->data!=key&&ptr->right!=NULL)
	{
		ptr=ptr->right;
	}
	if(ptr->right==NULL)
	{
		ptr->right=ne;
		ne->left=ptr;
	}
	else
	{
		ne->left=ptr;
		ne->right=ptr->right;
		ptr1=ptr->right;
		ptr->right=ne;
		ne->left=ne;
	}
	
}



void delete_pos()
{
	struct node *ptr;
	struct node *prev;
	struct node *next;
	int x;
	if (head == NULL)
	{
		printf("LInked List is Empty") ;
		
	}
	printf("Enter the Item you want to DELETE : ");
	scanf("%d", &x);
if(head->data==x)
	{
		ptr = head;
		head = head->right;
		if (head != NULL)
		{
			head->left=NULL;
		}
		free(ptr);
		
	}
else
	{
	ptr = head;
	while(ptr->data != x && ptr->right!=NULL)
	{
		ptr=ptr->right;
	}
	if(ptr!=NULL)
	{
		prev=ptr->left;
		next=ptr->right;
		prev->right=ptr->right;
		if(prev->right!=NULL)
		{	
		next->left=ptr->left;
		}
		free(ptr);
	}
}
}














