#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct TALNode{

int data;
struct TALNode* large;
struct TALNode* small;

};

void InsertTree(struct TALNode** root,int data){
    if(!(*root)){
struct  TALNode* newNode=(struct TALNode*)malloc(sizeof(struct TALNode));
newNode->data=data;
newNode->large=NULL;
newNode->small=NULL;
(*root)=newNode;
    }
    else if(data<(*root)->data){
    InsertTree(&(*root)->small,data);
    }else{
    InsertTree(&(*root)->large,data);
    }


}

void TraverseTree(struct TALNode* root){

if(!root){
return;
}
TraverseTree(root->small);
printf("%d  -->> ",root->data);
TraverseTree(root->large);

}


void Join(struct TALNode* a,struct TALNode* b){

a->large=b;
b->small=a;

}

struct TALNode* Append(struct TALNode* a,struct TALNode* b){

if(!a){
return b;
}
if(!b){
return a;
}
struct TALNode* aLast=a->small;
struct TALNode* bLast=b->small;

Join(aLast,b);
Join(bLast,a);

return a;
}


struct TALNode* ConvertBT(struct TALNode* root){
if(root==NULL){
return NULL;
}
struct TALNode* aList;
struct TALNode* bList;

aList=ConvertBT(root->small);
bList=ConvertBT(root->large);

root->small=root;
root->large=root;

aList=Append(aList,root);
aList=Append(aList,bList);

return aList;

}

void TraverseDLL(struct TALNode* head){

struct TALNode* tmpNode=head;

do{
printf(" <-- %d --> ",tmpNode->data);
tmpNode=tmpNode->large;

}while(tmpNode!=head);

}
int main(){

printf("\nCreating Tree...");
getch();
int i,data;
struct TALNode* root=NULL;
for(i=0;i<5;i++){
    printf("\nEnter data : ");
    scanf("%d",&data);
InsertTree(&root,data);
}

printf("%d nodes inserted ... \n");
getch();
printf("\nEnter to traverse...\n\n");
TraverseTree(root);

getch();

printf("\nEnter to convert BT to DLL\n");
getch();
root=ConvertBT(root);
printf("\nCreated...\n");
printf("\nEnter to traverse \n\n");


getch();

TraverseDLL(root);
getch();




return 0;
}
