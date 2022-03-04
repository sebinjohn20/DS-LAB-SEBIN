#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
void search();
struct node
{
int data;
struct node *next;
};
struct node *top=NULL;
void main()
{
int opt;
do
{
printf("Choose operation :\n 1.PUSH \n2. POP \n3. Display\n4.Search\n");
scanf("%d",&opt);
	switch(opt)
		{
  		case 1:
                        push();
                        break;
                  case 2:
                        pop();
                        break;
	  	 case 3:
                        display();
                        break;
		case 4:
                        search();
                        break;
		}
}
while(opt!=5);
}


void push()
{
	struct node *ne;
	int x;
	printf("Enter the element to PUSH\n");
	scanf("%d",&x);
	ne=(struct node *)malloc(sizeof(struct node));
	if (ne == NULL)
		{
		printf("Stack Overflow") ;
		return;
		}
	ne->data=x;
	ne->next= top;
	top = ne;
}


void pop()
{
struct node *ptr;
if (top == NULL)
	{
	printf("Stack Empty") ;
	return;
	}
printf("%d  is popped\n",top->data);
ptr=top;
top=top->next;
free(ptr);
}


void display()
{
struct node *ptr;
if (top == NULL)
	{
	printf("Stack Empty") ;
	return;
	}
else
	{
	ptr=top;
	while(ptr!=NULL)
		{
		printf("%d \t",ptr->data);
		ptr=ptr->next;
		}
	}

}


void search()
{
struct node *ptr;
int x;
printf("Enter the element to search\n");
scanf("%d",&x);
if (top == NULL)
	{
	printf("Stack Empty") ;
	return;
	}
else
	{
	ptr=top;
	while(ptr!=NULL)
		{
		if(ptr->data==x)
		{
		printf("Element Found\n");
		break;
		}
		ptr=ptr->next;
		}
		if(ptr==NULL)
	{
	printf("Element Not Found\n");
	}
	}


}

