#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
struct Node{
int vertex;
struct Node*next;
};
struct Graph{
struct Node*adjLists[MAX_VERTICES];
int visited[MAX_VERTICES];
};
struct Queue{
int items[MAX_VERTICES];
int front;
int rear;
};
struct Node*createNode(int v){
struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->vertex=v;
newNode->next=NULL;
return newNode;
}
struct Graph*createGraph(){
struct Graph*graph=(struct Graph*)malloc(sizeof(struct Graph));
int i;
for(i=0;i<MAX_VERTICES;i++){
graph->adjLists[i]=NULL;
graph->visited[i]=0;
}
return graph;
}
void addEdge(struct Graph*graph,int src,int dest){
struct Node*newNode=createNode(dest);
newNode->next=graph->adjLists[src];
graph->adjLists[src]=newNode;
newNode=createNode(src);
newNode->next=graph->adjLists[dest];
graph->adjLists[dest]=newNode;
}
struct Queue*createQueue(){
struct Queue*queue=(struct Queue*)malloc(sizeof(struct Queue));
queue->front=-1;
queue->rear=-1;
return queue;
}
int isEmpty(struct Queue*queue){
return queue->rear==-1;
}
void enqueue(struct Queue*queue,int value){
if(queue->rear==MAX_VERTICES-1)
printf("Queue is full\n");
else{
if (queue->front==-1)
queue->front=0;
queue->rear++;
queue->items[queue->rear]=value;
}
}
int dequeue(struct Queue*queue){
int item;
if(isEmpty(queue)){
printf("Queue is empty\n");
item=-1;
}else{
item=queue->items[queue->front];
queue->front++;
if(queue->front>queue->rear){
queue->front=queue->rear=-1;
}
}
return item;
}
void printGraph(struct Graph*graph){
int v;
for(v=0;v<MAX_VERTICES;v++){
struct Node*temp=graph->adjLists[v];
printf("\n Adjacency list of vertices %d\n",v);
while(temp){
printf("%d->",temp->vertex);
temp=temp->next;
}
printf("\n");
}
}
void BFS(struct Graph* graph,int startVertex){
struct Queue*queue=createQueue();
graph->visited[startVertex]=1;
enqueue(queue,startVertex);
while(!isEmpty(queue)){
int currentVertex=dequeue(queue);
printf("visited %d\n",currentVertex);
struct Node*temp=graph->adjLists[currentVertex];
while(temp){
int adjVertex=temp->vertex;
if(graph->visited[adjVertex]==0){
graph->visited[adjVertex]=1;
enqueue(queue,adjVertex);
}
temp=temp->next;
}
}
}
int main(){
struct Graph*graph=createGraph();
addEdge(graph,0,1);
addEdge(graph,0,2);
addEdge(graph,1,2);
addEdge(graph,1,3);
addEdge(graph,2,3);
printf("Graph:\n");
printGraph(graph);
printf("\n BFS Traversal starting from vertex 0:\n");
BFS(graph,0);
return 0;
}

OUTPUT:

Graph:

 Adjacency list of vertices 0
2->1->

 Adjacency list of vertices 1
3->2->0->

 Adjacency list of vertices 2
3->1->0->

 Adjacency list of vertices 3
2->1->

 Adjacency list of vertices 4


 Adjacency list of vertices 5


 Adjacency list of vertices 6


 Adjacency list of vertices 7


 Adjacency list of vertices 8


 Adjacency list of vertices 9


 Adjacency list of vertices 10


 Adjacency list of vertices 11


 Adjacency list of vertices 12


 Adjacency list of vertices 13


 Adjacency list of vertices 14


 Adjacency list of vertices 15


 Adjacency list of vertices 16


 Adjacency list of vertices 17


 Adjacency list of vertices 18


 Adjacency list of vertices 19


 Adjacency list of vertices 20


 Adjacency list of vertices 21


 Adjacency list of vertices 22


 Adjacency list of vertices 23


 Adjacency list of vertices 24


 Adjacency list of vertices 25


 Adjacency list of vertices 26


 Adjacency list of vertices 27


 Adjacency list of vertices 28


 Adjacency list of vertices 29


 Adjacency list of vertices 30


 Adjacency list of vertices 31


 Adjacency list of vertices 32


 Adjacency list of vertices 33


 Adjacency list of vertices 34


 Adjacency list of vertices 35


 Adjacency list of vertices 36


 Adjacency list of vertices 37


 Adjacency list of vertices 38


 Adjacency list of vertices 39


 Adjacency list of vertices 40


 Adjacency list of vertices 41


 Adjacency list of vertices 42


 Adjacency list of vertices 43


 Adjacency list of vertices 44


 Adjacency list of vertices 45


 Adjacency list of vertices 46


 Adjacency list of vertices 47


 Adjacency list of vertices 48


 Adjacency list of vertices 49


 Adjacency list of vertices 50


 Adjacency list of vertices 51


 Adjacency list of vertices 52


 Adjacency list of vertices 53


 Adjacency list of vertices 54


 Adjacency list of vertices 55


 Adjacency list of vertices 56


 Adjacency list of vertices 57


 Adjacency list of vertices 58


 Adjacency list of vertices 59


 Adjacency list of vertices 60


 Adjacency list of vertices 61


 Adjacency list of vertices 62


 Adjacency list of vertices 63


 Adjacency list of vertices 64


 Adjacency list of vertices 65


 Adjacency list of vertices 66


 Adjacency list of vertices 67


 Adjacency list of vertices 68


 Adjacency list of vertices 69


 Adjacency list of vertices 70


 Adjacency list of vertices 71


 Adjacency list of vertices 72


 Adjacency list of vertices 73


 Adjacency list of vertices 74


 Adjacency list of vertices 75


 Adjacency list of vertices 76


 Adjacency list of vertices 77


 Adjacency list of vertices 78


 Adjacency list of vertices 79


 Adjacency list of vertices 80


 Adjacency list of vertices 81


 Adjacency list of vertices 82


 Adjacency list of vertices 83


 Adjacency list of vertices 84


 Adjacency list of vertices 85


 Adjacency list of vertices 86


 Adjacency list of vertices 87


 Adjacency list of vertices 88


 Adjacency list of vertices 89


 Adjacency list of vertices 90


 Adjacency list of vertices 91


 Adjacency list of vertices 92


 Adjacency list of vertices 93


 Adjacency list of vertices 94


 Adjacency list of vertices 95


 Adjacency list of vertices 96


 Adjacency list of vertices 97


 Adjacency list of vertices 98


 Adjacency list of vertices 99


 BFS Traversal starting from vertex 0:
visited 0
visited 2
visited 1
visited 3


