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



int IsOperand(char op){

return (op<='9' && op>='0');

}



void PostfixEval(char exp[]){

int len=strlen(exp);
Node* stack=(Node*)malloc(sizeof(Node));
stack->top=-1;
stack->capacity=len;
stack->Array=(int*)malloc(sizeof(int)*len);

int i;
for(i=0;i<len;i++){
if(IsOperand(exp[i])){
Push(stack,exp[i]-48);
}
else{
    int a=Pop(stack);
    int b=Pop(stack);
    switch(exp[i]){
    case '+':
    Push(stack,a+b);
    break;
    case '-':
    Push(stack,b-a);
    break;
    case '*':
    Push(stack,a*b);
    break;
    case '/':
    Push(stack,b/a);
    break;
    }


}

}
printf("\n%d",Pop(stack));

}



int main(){
char expression[25];
printf("\nEnter the infix expression :   ");
scanf("%s",expression);
PostfixEval(expression);
return 0;
}
