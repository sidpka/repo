#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct SNode{
int top;
int capacity;
int *Array;
};



typedef struct SNode Node;

struct ADStack{
Node* ElementStack;
Node* MinStack;
};

void Resize(Node* stack){

stack->capacity*=2;
stack->Array=(int*)realloc(stack->Array,stack->capacity);
if(!stack->Array){
printf("\nError occurred\n");
}

}

void Push(Node** stack,int data){
if((*stack)->top==(*stack)->capacity-1){
Resize((*stack));
}

(*stack)->Array[++(*stack)->top]=data;
printf("\n\nTop element %d",(*stack)->Array[(*stack)->top]);
}

int Pop(Node* stack){

if(stack->top!=-1){

return stack->Array[stack->top--];

}

}
void Traverse(Node* stack){

int i;
printf("\n|_ %d _| <-- top ",stack->Array[stack->capacity-1]);
for(i=stack->capacity-2;i>=0;i--){
printf("\n|_ %d  _|",stack->Array[i]);
}

}


int StackEmpty(Node* stack){
if(stack->top==-1){
return 1;
}else{
return 0;
}
}
int Top(Node* stack){
return stack->Array[stack->top];
}
int main(){
int i,data;
//struct ADStack* mainRoot=(struct ADStack*)malloc(sizeof(struct ADStack));

Node* ElementStack=(Node*)malloc(sizeof(Node));
Node* MinStack=(Node*)malloc(sizeof(Node));
ElementStack->top=-1;
MinStack->top=-1;
ElementStack->capacity=6;
MinStack->capacity=3;
ElementStack->Array=(int*)malloc(sizeof(int )*ElementStack->capacity);
MinStack->Array=(int*)malloc(sizeof(int )* MinStack->capacity);

for(i=0;i<6;i++){
printf("\nPush into stack : ");
scanf("%d",&data);

Push(&(ElementStack),data);
if(StackEmpty(MinStack) || Top(MinStack)>=data){
Push(&(MinStack),data);
}
}

printf("\nPushed %d elements...",i);
getch();
printf("\nPress enter to traverse element stack....");
getch();
Traverse(ElementStack);
getch();
printf("\nPress enter to traverse min stack....");
getch();
Traverse(MinStack);
getch();

return 0;
}
