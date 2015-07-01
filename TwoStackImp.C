#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct SNode{

int top;
int top1;
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
    if(stack->top1-1>stack->top){
stack->Array[++stack->top]=data;
    }

}

void Push1(Node* stack,int data){
    if(stack->top1-1>stack->top){
stack->Array[--stack->top1]=data;
    }
}


int main(){
Node* stack=(Node*)malloc(sizeof(Node));
int size=5;
stack->top=-1;
stack->top1=size;
stack->capacity=size;
stack->Array=(int*)malloc(sizeof(int)*stack->capacity);

int i;
for(i=0;i<size;i++){
    if(i<3){
Push(stack,i+5);
    }else{
    Push1(stack,i+10);
    }
}
printf("\nIndex : %d   ",stack->top);
printf("Popped stack1 : %d",stack->Array[stack->top--]);
printf("\nIndex : %d   ",stack->top1);
printf("Popped stack2 : %d",stack->Array[stack->top1++]);

return 0;
}
