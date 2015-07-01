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

void ConvertITP(char exp[]){

int i;
int len=strlen(exp);
Node* stack=(Node*)malloc(sizeof(Node));
stack->top=-1;
stack->capacity=len;
stack->Array=(int*)malloc(sizeof(int)*len);

for(i=0;i<len;i++){
    if(IsOperand(exp[i])){
    printf("%c",exp[i]);
    }

    else if(exp[i]=='('){
            Push(stack,exp[i]);
            }
    else if(exp[i]==')'){

    while(!IsStackEmpty(stack) && Peek(stack)!='('){
          printf("%c",Pop(stack));
          }
          if(!IsStackEmpty(stack) &&  Peek(stack)!='('){
             printf("\nError");
             return;
             }else{
             Pop(stack);
             }


    }
    else{

    while(!IsStackEmpty(stack) && Pref(exp[i])<=Pref(Peek(stack))){

    printf("%c",Pop(stack));

    }
    Push(stack,exp[i]);

    }


}

while(!IsStackEmpty(stack)){
printf("%c",Pop(stack));
}

}

int main(){
char expression[25];
printf("\nEnter the infix expression :   ");
scanf("%s",expression);
ConvertITP(expression);
return 0;
}
