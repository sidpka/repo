#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct SNode{

int top;
int capacity;
int *Array;
};
typedef struct SNode Node;

int IsStackEmpty(Node* stack){
return stack->top==-1;
}

int Peek(Node* stack){
return stack->Array[stack->top];
}

int Pop(Node* stack){
return stack->Array[stack->top--];
}

void Push(Node* stack,int data){

stack->Array[++stack->top]=data;


}




void NGE(Node* stack,int* A){
int i;
int element ,next;
Push(stack,A[0]);
for(i=1;i<stack->capacity;i++){
    next=A[i];
if(!IsStackEmpty(stack)){
while(!IsStackEmpty(stack) && Peek(stack)<next){
element=Pop(stack);
printf("\n%d -- > %d",element,next);
}
Push(stack,next);
}else{
Push(stack,next);
}
}



while(!IsStackEmpty(stack)){
element=Pop(stack);
next=-1;
printf("\n%d -- > %d",element,next);
}
}

int main(){
Node* stack=(Node*)malloc(sizeof(Node));
int size=4;
stack->top=-1;
stack->capacity=size;
stack->Array=(int*)malloc(sizeof(int)*stack->capacity);
int i;
int* A=(int*)malloc(sizeof(int)*size);
for(i=0;i<size;i++){
scanf("%d",&A[i]);
}

int* S=(int*)malloc(sizeof(int)*size);
//S=Check(stack,S,A);
NGE(stack,A);
return 0;
}
