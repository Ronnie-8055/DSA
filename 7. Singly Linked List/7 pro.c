#include<stdio.h>
#include<stdlib.h>
struct node
{
char usn[20], name[10],branch[5];
int sem,phno;
struct node *link;
};
typedef struct node * NODE;
NODE temp,FIRST=NULL;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
x->link=NULL;
return x;
}
void read()
{
temp=getnode();
printf("Enter USN:\n");
scanf("%s",temp->usn);
printf("Enter NAME\n");
scanf("%s",temp->name);
printf("Enter Branch\n");
scanf("%s",temp->branch);
printf("Enter Semester\n");
scanf("%d",&temp->sem);
printf("Enter phno:\n");
scanf("%d",&temp->phno);
}

void create_SLL()
{
int n,i;
printf("Enter the number of students\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("\n Enter the details of %d students\n",i);
read();
if(FIRST==NULL)
FIRST=temp;
else
{
temp->link=FIRST;
FIRST=temp;
}
}
}
void display_count()
{
int count=1;
temp=FIRST;
printf("Student details:\n");
if(FIRST==NULL)
printf("Student detail is NULL and count is 0\n");
else
{
printf("USN\tNAME\tBRANCH\tSEMESTER\tPHNO\n");
while(temp->link!=NULL)
{
count++;
printf("%s\t%s\t%s\t%d\t\t%d\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
temp=temp->link;
}
printf("%s\t%s\t%s\t%d\t\t%d\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
printf("total node count is %d\n",count);
}
return;
}
void insert_front()
{
printf("Enter the details of student\n");
read();
if(FIRST==NULL)
FIRST=temp;
else
{
temp->link=FIRST;
FIRST=temp;
}
}
void insert_end()
{
NODE last=FIRST;
printf("Enter the details of student\n");
read();

if(FIRST==NULL)
FIRST=temp;
else
{
while(last->link!=NULL)
last=last->link;
last->link=temp;
}
}
void delete_front()
{
temp=FIRST;
if(FIRST==NULL)
printf("List is empty\n");
else
{
printf("deleted element is %s\n",temp->usn);
FIRST=FIRST->link;
free(temp);
}
return;
}

void delete_end()
{
NODE last=NULL;
temp=FIRST;
if(FIRST==NULL)
printf("List is empty\n");
else if(FIRST->link==NULL)
{
printf("Deleted element is %s\n",temp->usn);
free(FIRST);
FIRST=NULL;
}
else
{
while(temp->link!=NULL)
{
last=temp;
temp=temp->link;
}
last->link=NULL;
printf("Deleted element is %s\n",temp->usn);
free(temp);
}
return;
}
void main()
{
int choice;
while(1)
{
printf("1. Create SLL\n2.Display SSL\n3.Insert front\n4.Insert end\n5.Delete front\n6.Delete end\n7.EXIT\n");
printf("Enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:create_SLL();
break;
case 2:display_count();
break;
case 3:insert_front();
break;
case 4:insert_end();
break;
case 5:delete_front();
break;
case 6:delete_end();
break;
case 7:return;
default:printf("\nInvalid choice\n");
}
}
}
