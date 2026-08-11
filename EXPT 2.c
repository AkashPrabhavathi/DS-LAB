#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
int data;
struct Node *next;
}Node;
typedef struct
{
Node *head;
}CircularLinkedList;
void initCircularLinkedList(CircularLinkedList *list)
{
list->head==NULL;
}
void addCircular(CircularLinkedList *list,int element)
{
Node*new_Node=(Node*)malloc(sizeof(Node));
if(new_Node==NULL)
{
fprintf(stderr,"memory allocated failed\n");
exit(EXIT_FAILURE);
}
new_Node->data=element;
if(list->head==NULL)
{
list->head=new_Node;
new_Node->next=list->head;
}
else
{
Node*current=list->head;
while(current->next!=list->head)
{
current=current->next;
}
current->next=new_Node;
new_Node->next=list->head;
}
}
void removeCircular(CircularLinkedList *list,int element)
{
if(list->head==NULL)
{
printf("list is empty\n");
return;
}
Node *current=list->head;
Node *prev=NULL;
do{
if(current->data==element)
{
if(current==list->head && current->next==list->head)
{
list->head=NULL;
}
else if(current==list->head)
{
Node*temp=list->head;
while(temp->next!=list->head)
{
temp=temp->next;
}
temp->next=list->head->next;
list->head=list->head->next;
}
else
{
prev->next=current->next;
}
free(current);
printf("element %d removed from the list\n",element);
return;
}
prev=current;
current=current->next;
}
while(current!=list->head);
printf("element %d not found in the list\n",element);
}
void displayCircular(CircularLinkedList *list)
{
if(list->head==NULL)
{
printf("list is empty\n");
return;
}
Node *current=list->head;
printf("Circular Linked List:");
do{
printf("%d",current->data);
current=current->next;
}while(current!=list->head);
printf("\n");
}
int sizeCircular(CircularLinkedList *list)
{
if(list->head==NULL)
{
return 0;
}
int count=0;
Node*current=list->head;
do{
count++;
current=current->next;
}
while(current!=list->head);
return count;
}
int main()
{
CircularLinkedList list;
initCircularLinkedList(&list);
addCircular(&list,1);
addCircular(&list,2);
addCircular(&list,3);
printf("Circular Linked List after addding element:\n");
displayCircular(&list);
removeCircular(&list,2);
printf("Circular Linked List after removing element2:");
displayCircular(&list);
printf("size of Circular Linked List:%d\n",sizeCircular(&list));
return 0;
}  

OUTPUT:

Circular Linked List after addding element:
Circular Linked List:123
element 2 removed from the list
Circular Linked List after removing element2:Circular Linked List:13
size of Circular Linked List:2

