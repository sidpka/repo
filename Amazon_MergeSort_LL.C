#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct LL{
int data;
LL* next;
};
typedef struct LL Node;


Node* NewNode(int data){

Node* newNode=(Node*)malloc(sizeof(Node));
newNode->data=data;
//newNode->next=NULL;

}

void Insert(Node** head,int data){
Node* newNode=NewNode(data);
newNode->next=*head;
*head=newNode;
}


void Traverse(Node* head){
if(head==NULL){
return;
}

printf("%d  ",head->data);
Traverse(head->next);

}


void FrontBackSplit(Node* head,Node** a,Node** b){

Node* slowPtr;
Node* fastPtr;

if(head==NULL || head->next==NULL){

*a=head;
*b=NULL;

}else{
slowPtr=head;
fastPtr=head->next;
while(fastPtr!=NULL){

fastPtr=fastPtr->next;
if(fastPtr!=NULL){
slowPtr=slowPtr->next;
fastPtr=fastPtr->next;
}
}
}

(*a)=head;
(*b)=slowPtr->next;
slowPtr->next=NULL;

}


Node* SortedMerge(Node* a,Node* b){
Node* result=NULL;
if(a==NULL){
return b;
}

if(b==NULL){
return a;
}

if(a->data<=b->data){
result=a;
result->next=SortedMerge(a->next,b);
}else{
result=b;
result->next=SortedMerge(a,b->next);
}

return result;



}


void MergeSort(Node** headRef){
Node* head=*headRef;
Node* a;
Node* b;

if(head==NULL || head->next==NULL){
return;
}

FrontBackSplit(head,&a,&b);
//printf("\nHere");
MergeSort(&a);
MergeSort(&b);

*headRef=SortedMerge(a,b);

}


int main(){

printf("\nEnter the number of nodes : ");
int n;
scanf("%d",&n);

int i;
int data;
Node* result=NULL;
Node** lPtr=&result;
for(i=0;i<n;i++){
printf("\nEnter data : ");
scanf("%d",&data);
Insert(lPtr,data);
(lPtr)=(&(*lPtr)->next);
}

printf("\nPress enter to traverse : \n");
Traverse(result);

printf("\nPress enter to merge \n");
MergeSort(&result);
getch();
Traverse(result);


return 0;
}
