#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node*next;
};
struct Node* create(int data);
void insertAtEnd(struct Node **head,int data);
void insertAtPosition(struct Node **head,int data,int position);
int searchElement(struct Node*head,int data);
void deleteElement(struct Node**head,int position);
void displayList(struct Node*head);
int main()
{
struct Node*head=NULL;
int choice,data,position,result;
while(1)
{
printf("\n Singly Linked List operations Menu:\n");
printf("1.Insert at End\n");
printf("2.Insert at Position\n");
printf("3.Search Element\n");
printf("4.Delete Element\n");
printf("5.Display List\n");
printf("6.Exit\n");
printf("Enter Your Choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter data to insert at end:");
scanf("%d",&data);
insertAtEnd(&head,data);
break;
case 2:
printf("Enter data to insert:");
scanf("%d",&data);
printf("Enter position to insert(0-based index):");
scanf("%d",&position);
insertAtPosition(&head,data,position);
break;
case 3:
printf("Enter Element to search:");
scanf("%d",&data);
result=searchElement(head,data);
if(result!=-1)
printf("Element found at position:%d\n",result);
else
printf("Element not found in the list.\n");
break;
case 4:
printf("Element position to delete (0-based index):");
scanf("%d",&position);
deleteElement(&head,position);
break;
case 5:
displayList(head);
break;
case 6:
while(head!=NULL)
{
struct Node*temp=head;
head=head->next;
free(temp);
}
return 0;
default:
printf("Invalid choice! Please enter a valid option.\n");
}
}
return 0;
}
struct Node* createNode(int data)
{
struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
if(newNode==NULL)
{
printf("Memory allocatioin failed\n");
exit (EXIT_FAILURE);
}
newNode->data=data;
newNode->next=NULL;
return newNode;
}
void insertAtEnd(struct Node**head,int data)
{
struct Node *newNode=createNode(data);
if(*head==NULL)
{
*head=newNode;
return;
}
struct Node *temp=*head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=newNode;
}
void insertAtPosition(struct Node**head,int data,int position)
{
if(position<0)
{
printf("Error:Invalid position.\n");
return;
}
struct Node*newNode=createNode(data);
if(position==0)
{
newNode->next= *head;
*head=newNode;
return;
}
struct Node*current=*head;
struct Node*previous=NULL;
int currentPos=0;
while (current!=NULL && currentPos<position)
{
previous=current;
current=current->next;
currentPos++;
}
if(currentPos!=position)
{
printf("Error:Invalild Position.\n");
free(newNode);
return;
}
newNode->next=current;
previous->next=newNode;
}
int searchElement(struct Node*head,int data)
{
struct Node*temp=head;
int position=0;
while(temp!=NULL)
{
if(temp->data==data)
{
return position;
}
temp=temp->next;
position++;
}
return -1;
}
void deleteElement(struct Node**head,int position)
{
if(*head==NULL)
{
printf("Error:Invalid position.\n");
return;
}
struct Node*temp=*head;
if(position==0)
{
*head=temp->next;
free(temp);
return;
}
struct Node*previous=NULL;
int currentPos=0;
while (temp!=NULL && currentPos<position)
{
previous=temp;
temp=temp->next;
currentPos++;
}
if(temp==NULL)
{
printf("Error:Invalild Position.\n");
return;
}
previous->next=temp->next;
free(temp);
}
void displayList(struct Node*head)
{
if(head==NULL)
{
printf("List is empty.\n");
return;
}
printf("Linked List:");
struct Node*temp=head;
while (temp!=NULL)
{
printf("%d->",temp->data);
temp=temp->next;
}
printf("NULL\n");
}


OUTPUT:

 Singly Linked List operations Menu:
1.Insert at End
2.Insert at Position
3.Search Element
4.Delete Element
5.Display List
6.Exit
Enter Your Choice:1
Enter data to insert at end:10

 Singly Linked List operations Menu:
1.Insert at End
2.Insert at Position
3.Search Element
4.Delete Element
5.Display List
6.Exit
Enter Your Choice:2
Enter data to insert:20
Enter position to insert(0-based index):1

 Singly Linked List operations Menu:
1.Insert at End
2.Insert at Position
3.Search Element
4.Delete Element
5.Display List
6.Exit
Enter Your Choice:5
Linked List:10->20->NULL

 Singly Linked List operations Menu:
1.Insert at End
2.Insert at Position
3.Search Element
4.Delete Element
5.Display List
6.Exit
Enter Your Choice:3
Enter Element to search:20
Element found at position:1

 Singly Linked List operations Menu:
1.Insert at End
2.Insert at Position
3.Search Element
4.Delete Element
5.Display List
6.Exit
Enter Your Choice:4
Element position to delete (0-based index):1

 Singly Linked List operations Menu:
1.Insert at End
2.Insert at Position
3.Search Element
4.Delete Element
5.Display List
6.Exit
Enter Your Choice:5
Linked List:10->NULL

 Singly Linked List operations Menu:
1.Insert at End
2.Insert at Position
3.Search Element
4.Delete Element
5.Display List
6.Exit
Enter Your Choice:6








































