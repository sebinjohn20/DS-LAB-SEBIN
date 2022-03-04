#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;

 struct node *next;
};
 struct node *first[20];
 void makeset(int);
 void unions(int,int);
 int find(int);
 int n=0;
 struct edge
 {
  int start;
  int weight;
  int end;
 };
 struct edge adj[30], A[30];
void main()
{

 int i,nv,sum,k,en,s,w,e,u,v,c,count;
 printf("Enter no: of vertices: ");
 scanf("%d",&nv);
 for(i=1;i<=nv;i++)
 makeset(i);
 printf("Enter the no. of edges:");
 scanf("%d",&e);
 printf("Enter the edjes\n");
 printf("start end weight\n");
 c=-1;
 for(i=1;i<=e;i++)
 {
  scanf("%d %d %d",&s,&en,&w);
  for(k=c;k>=0;k--)
  {
   if(adj[k].weight>w)
   adj[k+1]=adj[k];
   else
   break;
  }

  adj[k+1].start=s;
  adj[k+1].end=en;
  adj[k+1].weight=w;
  c++;
 }
 count=0;
 for(i=0;i<c;i++)
 {
  u=adj[i].start;
  v=adj[i].end;
  if(find(u)!=find(v))
  {
   A[count].start=u;
   A[count].end=v;
   A[count].weight=adj[i].weight;
   unions(u,v);
   count++;
  }
 }
 printf("\nSpanning Tree edjes\n");
 sum=0;
 for(i=0;i<count;i++)
 {
  printf("(%d->%d) w:%d\n" ,A[i].start,A[i].end,A[i].weight);
  sum=sum+A[i].weight;
 }
 printf("\nTotal Cost=%d" ,sum);
}
void makeset(int x)
{
 int pos;
 pos=find(x);
 if(pos==-1)
 {
  first[n]=(struct node *)malloc(sizeof(struct node));
  first[n]->data=x;
  first[n]->next=NULL;
  n++;
 }
 else
 {
  printf("Number already exist\n");
 }
}
void unions(int x,int y)
{
struct node *p;
int i,j;
i=find(x);
  j=find(y);
  if (i==-1 || j ==-1)
      return;
  if (i==j)

      printf("Both are in the same set");
    else
    p=first[i];
      while(p->next!=NULL)
{
       p=p->next;
      }
      p->next=first[j];
      first[j]=NULL;


}
int find(int x)
{
 struct node *p;
 int i,j,flag;
 flag=0;
 for(i=0;i<n;i++)
 {
  p=first[i];
  while(p!=NULL)
  {
   if (p->data==x)
   {
    flag=1;
    break;
   }
   p=p->next;
  }
  if (flag==1)
  break;
 }
 if(flag==1)
 return i;
 else
 return -1;
}
