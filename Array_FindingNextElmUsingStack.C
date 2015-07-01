#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Stack{
int top;
int capacity;
int* SArray;
};

typedef struct Stack SNode;

SNode* CreateStack(int n){
SNode* tmpNode=(SNode*)malloc(sizeof(SNode));
tmpNode->top=-1;
tmpNode->capacity=n;
tmpNode->SArray=(int*)malloc(sizeof(int)*n);
return tmpNode;
}

void Push(SNode* stack,int data){
stack->SArray[++(stack->top)]=data;
}

int IsEmptyStack(SNode* stack){
return stack->top==-1;
}

int Pop(SNode* stack){
if(!IsEmptyStack(stack)){

return stack->SArray[stack->top--];
}

}

int Top(SNode* stack){
return stack->SArray[stack->top];
}

void PrintPair(SNode* stack,int data){
while(Top(stack)<data && !IsEmptyStack(stack)){
printf("\n%d  -->  %d",Pop(stack),data);
}
}

void FindNextAll(int* arr,int n){
SNode* stack=CreateStack(n);
//printf("\nStack : %d",stack->top);
Push(stack,arr[0]);
//printf("\n%d",Top(stack));
int i;
for(i=1;i<n;i++){
if(arr[i]<=Top(stack)){
Push(stack,arr[i]);
}else{
PrintPair(stack,arr[i]);
Push(stack,arr[i]);
}
}

while(!IsEmptyStack(stack)){
printf("\n%d  -->  %d",Pop(stack),-1);
}

}

int main(){
int arr[]={2,1,4,8,6,3,1,2};
int n=sizeof(arr)/sizeof(arr[0]);
printf("\nPress enter :\n\n");
getch();
FindNextAll(arr,n);
getch();
return 0;
}
