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

int Pref(int ch){
switch(ch){
case '+' :
case  '-':
return 1;

case  '*':
case '/' :
return 2;

case  '^':
return 3;
default:
return -1;


}
}

int IsOperand(char op){

return (op<='z' && op>='a')||(op<='Z' && op>='A');

}

int IsBExp(char op){

return (op=='(' || op=='{' || op=='[');
}

int IsEExp(char op){

return (op==')' || op=='}' || op==']');
}

char Mapper(char op){
switch(op){
case ')':
       return '(';
case '}':
return '{';

case ']':
return '[';

}
}

void Check(char exp[]){

int i;
int len=strlen(exp);
Node* stack=(Node*)malloc(sizeof(Node));
stack->top=-1;
stack->capacity=len;
stack->Array=(int*)malloc(sizeof(int)*len);
int flag=1;
for(i=0;i<len;i++){

    if(IsBExp(exp[i])){
    Push(stack,exp[i]);
    }
    else if(IsEExp(exp[i])){
    if(Peek(stack)!=Mapper(exp[i])){
     flag=0;break;
    }
    Pop(stack);
    }


}
if(!IsStackEmpty(stack)){
flag=0;
}
if(flag){
printf("\nBalanced expression");
}
else{
printf("\nUnbalanced expression");
}
}
int main(){
char expression[25];
printf("\nEnter the  expression :   ");
scanf("%s",expression);
Check(expression);
return 0;
}
