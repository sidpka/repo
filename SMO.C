#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct DNode{
int data;
struct DNode* next;
struct DNode* prev;
};
typedef struct DNode Node;

struct SNode{
Node* head;
Node* midNode;
int count;
};
typedef struct SNode STNode;


void Push(STNode* stack,int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->prev=NULL;
    newNode->data=data;

if(!stack->head){
newNode->next=NULL;
stack->head=newNode;
stack->midNode=newNode;
stack->count++;
return;
}

newNode->next=stack->head;
stack->head->prev=newNode;
stack->count++;
stack->head=newNode;
if(!(stack->count &1)){
stack->midNode=stack->midNode->prev;
}


}

void Traverse(STNode* stack){

Node* tmpNode=stack->head;
while(tmpNode){
printf("%d-->>",tmpNode->data);
tmpNode=tmpNode->next;
}

}

int main(){
STNode* stack=(STNode*)malloc(sizeof(STNode));
stack->count=0;
stack->head=NULL;
stack->midNode=NULL;
int i,data;

for(i=0;i<5;i++){
printf("\nEnter data : ");
scanf("%d",&data);
Push(stack,data);
//printf("\nMiddle element is : %d",stack->midNode->data);
}

printf("\n%d nodes inserted ",i);
getch();
printf("\nPress enter to traverse ..\n\n");
getch();

Traverse(stack);
getch();
printf("\nMiddle element is : %d",stack->midNode->data);
return 0;
}
