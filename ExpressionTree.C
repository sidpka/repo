#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct Tree{
int data;
struct Tree* left;
struct Tree* right;
};
typedef struct Tree TNode;


struct StackNode{
TNode* data;
struct StackNode* next;
};
typedef struct StackNode SNode;

void Push(SNode** stack,TNode* nodeToInsert){
    SNode* newNode=(SNode*)malloc(sizeof(SNode));
    newNode->data=nodeToInsert;

if(!(*stack)){
newNode->next=NULL;
(*stack)=newNode;
}else{
newNode->next=(*stack);
(*stack)=newNode;
}
}

TNode* Pop(SNode** stack){
SNode* tmpNode=(*stack);
(*stack)=(tmpNode)->next;
return tmpNode->data;
}

int IsEmptyStack(SNode* stack){
return stack==NULL;
}

int IsOperand(char x){
return (x>=65 && x<=90)||(x>=97 && x<=122);
}

TNode* CreateExpressionTree(char* exp){
int size=strlen(exp);
int i;
TNode* tmp1,*tmp2;
SNode* stack=NULL;

for(i=0;i<size;i++){
if(IsOperand(exp[i])){
tmp1=(TNode*)malloc(sizeof(TNode));
tmp1->data=exp[i];
tmp1->left=NULL;
tmp1->right=NULL;
Push(&stack,tmp1);
}else{
TNode* newNode=(TNode*)malloc(sizeof(TNode));

tmp1=Pop(&stack);
tmp2=Pop(&stack);

newNode->data=exp[i];
newNode->right=tmp1;
newNode->left=tmp2;
Push(&stack,newNode);
}
}
return Pop(&stack);
}

void InOrderTraversal(TNode* root){
    if(!root){
    return;
    }
InOrderTraversal(root->left);
printf("%c <-->  ",root->data);
InOrderTraversal(root->right);
}

int main(){
char exp[20];
printf("\nEnter the expression : ");
scanf("%s",exp);
TNode* root=CreateExpressionTree(exp);
printf("\nExpression Tree Created\n");
getch();

printf("\nPress enter to do inorder traversal... ");
getch();
InOrderTraversal(root);
getch();
return 0;
}
