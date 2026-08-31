#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node*next;
};
struct Queue{
struct Node*front;
struct Node*rear;
};
struct Node*createNode(int data);
void initializeQueue(struct Queue*queue);
void enqueue(struct Queue*queue,int data);
int dequeue(struct Queue*queue);
void displayQueue(struct Queue*queue);
int main(){
struct Queue queue;
int choice,element;
initializeQueue(&queue);
while(1){
printf("\nQueue operations Menu:\n");
printf("1.Enqueue\n");
printf("2.dequeue\n");
printf("3.Display\n");
printf("4.Exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice){
case 1:
printf("enter element to enqueue:");
scanf("%d",&element);
enqueue(&queue,element);
break;
case 2:
element=dequeue(&queue);
if(element!=-1)
printf("Dequeued element:%d\n",element);
break;
case 3:
displayQueue(&queue);
break;
case 4:
exit(0);
default:
printf("Invalid choice!Please enter a valid option.\n");
}
}
return 0;
}
struct Node*createNode(int data){
struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
if(!newNode){
printf("Memory allocation error\n");
exit(1);
}
newNode->data=data;
newNode->next=NULL;
return newNode;
}
void initializeQueue(struct Queue*queue){
queue->front=NULL;
queue->rear=NULL;
}
void enqueue(struct Queue*queue,int data){
struct Node*newNode=createNode(data);
if(queue->rear==NULL){
queue->front=queue->rear=newNode;
printf("element enqueued:%d\n",data);
return;
}
queue->rear->next=newNode;
queue->rear=newNode;
printf("element enqueued:%d\n",data);
}
int dequeue(struct Queue*queue){
if(queue->front==NULL){
printf("error:Queue underflow.cannot dequeue element.\n");
return-1;
}
struct Node*temp=queue->front;
int dequeuedElement=temp->data;
queue->front=queue->front->next;
if(queue->front==NULL){
queue->rear=NULL;
}
free(temp);
return dequeuedElement;
}
void displayQueue(struct Queue*queue){
if(queue->front==NULL){
printf("Queue is empty.\n");
return;
}
printf("Queue element:");
struct Node*temp=queue->front;
while(temp!=NULL){
printf("%d",temp->data);
temp=temp->next;
}
printf("\n");
}



OUTPUT:

Queue operations Menu:
1.Enqueue
2.dequeue
3.Display
4.Exit
enter your choice:1
enter element to enqueue:10
element enqueued:10

Queue operations Menu:
1.Enqueue
2.dequeue
3.Display
4.Exit
enter your choice:1
enter element to enqueue:20
element enqueued:20

Queue operations Menu:
1.Enqueue
2.dequeue
3.Display
4.Exit
enter your choice:1
enter element to enqueue:30
element enqueued:30

Queue operations Menu:
1.Enqueue
2.dequeue
3.Display
4.Exit
enter your choice:3
Queue element:102030

Queue operations Menu:
1.Enqueue
2.dequeue
3.Display
4.Exit
enter your choice:2
Dequeued element:10

Queue operations Menu:
1.Enqueue
2.dequeue
3.Display
4.Exit
enter your choice:3
Queue element:2030

Queue operations Menu:
1.Enqueue
2.dequeue
3.Display
4.Exit
enter your choice:4
