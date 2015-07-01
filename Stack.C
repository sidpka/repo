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
int main(){
int i,data;
Node* stack=(Node*)malloc(sizeof(Node));
stack->top=-1;
stack->capacity=1;
stack->Array=(int*)malloc(sizeof(int )* stack->capacity );

for(i=0;i<12;i++){
printf("\nPush into stack : ");
scanf("%d",&data);
Push(stack,data);
}

printf("\nPushed %d elements...",i);
getch();
printf("\nPress enter to traverse...");
getch();
Traverse(stack);
getch();
printf("\n\nLIFO : %d",Pop(stack));

return 0;
}
