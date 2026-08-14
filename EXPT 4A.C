#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* createNode(int data);
void push(struct Node** top, int data);
int pop(struct Node**top);
void displayStack(struct Node* top);
int main() {
struct Node*top = NULL;
int choice, element;
while (1) {
printf("\nStack Operations Menu:\n");
printf("1.Push\n");
printf("2.Pop\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice) {
case 1:
printf("Enter element to push:");
scanf("%d", &element);
push(&top, element);
break;
case 2:
element = pop(&top);
if(element !=-1)
printf("Popped element:%d\n", element);
break;
case 3:
displayStack(top);
break;
case 4:
exit(0);
default:
printf("Invalid choice!@ Please enter a valid option.\n");
}
}
return 0;
}
struct Node* createNode(int data) {
struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
if (!newNode) {
printf("Memory allocation error\n");
exit(1);
}
newNode->data = data;
newNode->next = NULL;
return newNode;
}
void push(struct Node**top, int data) {
struct Node* newNode = createNode(data);
newNode->next = *top;
*top = newNode;
printf("Element pushed: %d\n", data);
}
int pop(struct Node**top) {
if (*top == NULL) {
printf("Error: Stack underflow. connot pop element.\n");
return -1;
}
struct Node*temp = *top;
int poppedElement= temp->data;
*top = (*top)->next;
free(temp);
return poppedElement;
}
void displayStack(struct Node*top) {
if (top ==NULL) {
printf("Stack is Empty.\n");
return;
}
printf("Stack elements:");
struct Node*temp = top;
while (temp != NULL) {
printf("%d", temp->data);
temp = temp->next;
}
printf("\n");
}

OUTPUT:

Stack Operations Menu:
1.Push
2.Pop
3. Display
4. Exit
Enter your choice:1
Enter element to push:10
Element pushed: 10

Stack Operations Menu:
1.Push
2.Pop
3. Display
4. Exit
Enter your choice:1
Enter element to push:20
Element pushed: 20

Stack Operations Menu:
1.Push
2.Pop
3. Display
4. Exit
Enter your choice:1
Enter element to push:30
Element pushed: 30

Stack Operations Menu:
1.Push
2.Pop
3. Display
4. Exit
Enter your choice:3
Stack elements:302010

Stack Operations Menu:
1.Push
2.Pop
3. Display
4. Exit
Enter your choice:2
Popped element:30

Stack Operations Menu:
1.Push
2.Pop
3. Display
4. Exit
Enter your choice:3
Stack elements:2010

Stack Operations Menu:
1.Push
2.Pop
3. Display
4. Exit
Enter your choice:4
