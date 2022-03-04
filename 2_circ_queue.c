#include<stdio.h>
int s=4;
int front=-1,rear=-1;
void insert(int *);
void del(int *);
void search(int *);
void display(int *);

void main()
{
	int q[20], option;
	do
	{
	printf("\n menu\n 1.Insert an Element \n 2.Delete an Element\n 3.Search an Element\n 4.Dispaly \n 5 Exit \n enter the option");
	scanf("%d",&option);
	switch(option)
	{
	case 1:insert(q);
	       break;
	case 2:del(q);
	       break;
	case 3:search(q);
	       break;
	case 4:display(q);
	      break;
	default:printf("exited");
	}
	}
	while(option!=5);
}

void insert(int *q)
{
	if(front==(rear+1)%s)
	{
	printf("queue is full \n");
	return;
	}
	if(front==-1)
	front=0;
	rear=(rear+1)%s;
	printf("enter the element \n");
	scanf("%d",&q[rear]);
}


void del(int *q)
{
	if(front==-1)
	{
	printf("queue empty\n");
	return;
	}
	printf("deleted element %d \n",q[front]);
	if(front==rear)
	{
	front=rear=-1;
	}
	else
	{
	front=(front+1)%s;
	}
	return;
}

void search(int *q)
{
	int se,f;
	printf("enter the element to be search");
	scanf("%d",&se);
	if(front==-1)
	{
	printf("q is empty\n");
	return;
	}
	f=front;
	while(1)
	{
	if(se==q[f])
	{
	printf("element found");
	break;
	}
	if(f==rear)
	{
	printf("element not found");
	break; 
	}
	f=(f+1)%s;
	}
	return;
	}
void display(int *q)
	{
	int f;
	if(front==-1)
	{
	printf("q  empty\n");
	return;
	}
	f=front;
	while(1)
	{
	printf("%d \n",q[f]);
	if(f==rear)
	break;
	f=(f+1)%s;
	}
	return;
}
