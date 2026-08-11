#include <stdio.h>
#define MAX_SIZE 100
void createArray(int arr[],int*size);
void insertElement(int arr[],int*size,int element, int position);
int searchElement(int arr[],int iosze,int element);
void deleteElement(int arr[],int*size,int position);
void displayArray(int arr[],int size);
int main() {
int arr[MAX_SIZE];
int size=0;
int choice,element,position,result;
while(1){
printf("\n array operation menu:\n");
printf("1. create array\n");
printf("2. inserty element\n");
printf("3. search element\n");
printf("4.delete element\n");
printf("5.display array\n");
printf("6. exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice){
case 1:
createArray(arr,&size);
break;
case 2:
printf("enter element to insert:");
scanf("%d",&element);
printf("enter position to insert (0 to %d):",size);
scanf ("%d",&position);
insertElement(arr,&size,element,position);
break;
case 3:
printf("enter element to search:");
scanf("%d",&element);
result= searchElement(arr,size,element);
if(result !=-1)
printf("element found at position:%d\n",result);
else
printf("element not found in the array.\n");
break;
case 4:
printf("enter position to delete (0to %d):",size-1);
scanf("%d",&position);
deleteElement(arr,&size,position);
break;
case 5:
displayArray(arr,size);
break;
case 6:
return 0;
default:
printf("invalid choice!please enter a valid option.\n");
}
}
return 0;
}
void createArray(int arr[],int*size){
int n,i;
printf("enter the number of elements:");
scanf("%d",&n);
if(n>MAX_SIZE){
printf("error: number of elements exceeds the maximum array size.\n");
return;
}
printf("enter %d element:",n);
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
*size=n;
printf("array created successfully.\n");
}
void insertElement(int arr[],int*size,int element, int position){
if(*size>=MAX_SIZE){
printf("error:array is full.cannot insert element.\n");
return;
}
if(position<0||position>*size){
printf("error:invalid position.\n");
return;
}
for(int i=*size;i>position;i--){
arr[i]=arr[i-1];
}
arr[position]=element;
(*size)++;
printf("element inserted successfully\n");
}
int searchElement(int arr[],int size,int element){
for(int i=0;i<size;i++){
if(arr[i]==element){
return i;
}
}
return-1;
}
void deleteElement(int arr[],int*size,int position){
if(position<0|| position>=*size){
printf("error:invalid position\n");
return;
}
for(int i=position;i<*size-1; i++){
arr[i]=arr[i+1];
}
(*size)--;
printf("element deleted successfully\n");
}
void displayArray(int arr[],int size){
if(size==0){
printf("array is empty\n");
return;
}
printf("array elements:");
for(int i=0;i<size;i++){
printf("%d",arr[i]);
}
printf("\n");
}

OUTPUT:

 array operation menu:
1. create array
2. inserty element
3. search element
4.delete element
5.display array
6. exit
enter your choice:1
enter the number of elements:5
enter 5 element:1 2 3 4 5
array created successfully.

 array operation menu:
1. create array
2. inserty element
3. search element
4.delete element
5.display array
6. exit
enter your choice:2
enter element to insert:10
enter position to insert (0 to 5):2
element inserted successfully

 array operation menu:
1. create array
2. inserty element
3. search element
4.delete element
5.display array
6. exit
enter your choice:5
array elements:1 2 10 3 4 5

 array operation menu:
1. create array
2. inserty element
3. search element
4.delete element
5.display array
6. exit
enter your choice:3
enter element to search:10
element found at position:2

 array operation menu:
1. create array
2. inserty element
3. search element
4.delete element
5.display array
6. exit
enter your choice:2
enter element to insert:10
enter position to insert (0 to 6):2
element inserted successfully

 array operation menu:
1. create array
2. inserty element
3. search element
4.delete element
5.display array
6. exit
enter your choice:4
enter position to delete (0to 6):2
element deleted successfully

 array operation menu:
1. create array
2. inserty element
3. search element
4.delete element
5.display array
6. exit
enter your choice:5
array elements:1 2 3 4 5




