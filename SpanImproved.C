#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct SNode{
int top;
int capacity;
int *Array;

};

typedef struct SNode Node;

void Resize(Node* stack){

stack->capacity*=2;
stack->Array=(int*)realloc(stack->Array,stack->capacity);
if(!stack->Array){
printf("\nError occurred\n");
}

}

void Push(Node* stack,int data){
if(stack->top==stack->capacity-1){
Resize(stack);
}

stack->Array[++stack->top]=data;

}

int Pop(Node* stack){

if(stack->top!=-1){

return stack->Array[stack->top--];

}

}
void Traverse(Node* stack){

int i;
for(i=stack->capacity-1;i>=0;i--){
printf("\n|_ %d _|",stack->Array[i]);
}

}
int StackEmpty(Node* stack){
if(stack->top==-1){
return 1;
}
else{
return 0;
}
}
int Top(Node* stack){
return stack->Array[stack->top];
}
int main(){
int i,data;
Node* stack=(Node*)malloc(sizeof(Node));
stack->top=-1;
stack->capacity=6;
stack->Array=(int*)malloc(sizeof(int )* stack->capacity );

int A[6]={6,3,4,5,2,8};
int S[6];
int P;

for(i=0;i<6;i++){
while(!StackEmpty(stack)){
if(A[i]>A[Top(stack)]){
Pop(stack);
}
else{
break;
}
}

if(StackEmpty(stack)){
P=-1;
}
else{
P=Top(stack);
}
S[i]=i-P;
Push(stack,i);

}

printf("\nSpan \n");
for(i=0;i<6;i++){
printf("%d  ",S[i]);
}
return 0;
}
