#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct SNode{
int top;
int capacity;
char *Array;

};

typedef struct SNode Node;

void Resize(Node* stack){

stack->capacity*=2;
stack->Array=(char*)realloc(stack->Array,stack->capacity);
if(!stack->Array){
printf("\nError occurred\n");
}

}

void Push(Node* stack,char data){
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
printf("\n|_ %c _| <-- top ",stack->Array[stack->capacity-1]);
for(i=stack->capacity-2;i>=0;i--){
printf("\n|_ %c _|",stack->Array[i]);
}

}
int StackEmpty(Node* stack){
if(stack->top!=-1){
return 1;
}else{
return 0;
}
}
int main(){
int i;
char data,tmpData;
Node* stack=(Node*)malloc(sizeof(Node));
stack->top=-1;
stack->capacity=1;
stack->Array=(char*)malloc(sizeof(char )* stack->capacity );
int choice=1;
for(i=0;i<11;i++){

printf("\nEnter next character : ");
getchar(data);
if(data=='(' || data=='[' || data == '{'){
   Push(stack,data);
   }
if(data==')' || data==']' || data == '}'){
   tmpData=Pop(stack);
   if(tmpData==data){
   printf("\nOk Passed this stage...");
   }else{
   printf("\nNot balanced symbol..");
   break;
   }
}

if(data=='0'){
if(!StackEmpty(stack)){
printf("\nBalanced symbols... Passed all stages...");
}else{
printf("\nFailed...");
}
break;
}
}

return 0;
}
