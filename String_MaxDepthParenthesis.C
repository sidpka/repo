#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct StackNode{
int top;
int n;
char* array;
};
typedef struct StackNode Stack;

Stack* CreateStack(int n){

Stack* tmpNode=(Stack*)malloc(sizeof(Stack));
tmpNode->top=-1;
tmpNode->n=n;
tmpNode->array=(char*)malloc(sizeof(char)*n);

return tmpNode;
}

void Push(Stack* node,char ch){
if(node->top<node->n-1){
node->array[++node->top]=ch;
}

}

char Pop(Stack* node){

if(node->top>=0){
return node->array[node->top--];
}

}

int IsEmptyStack(Stack* node){

return node->top==-1;
}

int max(int a,int b){

return a>b?a:b;
}

int FindDepth(char str[]){

int n=strlen(str);
Stack* stack=CreateStack(n);
int i;
int len=0;
for(i=0;i<n;i++){
if(str[i]=='('){
   Push(stack,str[i]);
   //printf("\n%c",stack->array[stack->top]);
   len=max(len,stack->top+1);
   }
else if(str[i]==')'){
if(IsEmptyStack(stack)){
return -1;
}else if(stack->array[stack->top]!='('){
         return -1;
         }else{
         Pop(stack);
         }
}

}

//printf("\nTop : %d",stack->top);
if(!IsEmptyStack(stack)){
return -1;
}

return len;
}


int FindDepth2(char str[]){

int n=strlen(str);

int curMax=0;
int max=0;

int i;

for(i=0;i<n;i++){

if(str[i]=='('){
   curMax++;
   if(curMax>max){
   max=curMax;
   }
   }
else if(str[i]==')'){
if(curMax>0){
curMax--;
}else{
return -1;
}


}
}


if(curMax!=0){
return -1;
}

return max;
}


int main(){


char str[]="( ((X)) (((Y))) )";

//int result=FindDepth(str);
int result=FindDepth2(str);
if(result==-1){
printf("\nInvalid ");
}else{
printf("\nMax depth : %d",result);
}



return 0;
}
