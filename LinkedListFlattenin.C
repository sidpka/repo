#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct LNode{
int data;
struct LNode* next;
};

struct HNode{
int count;
struct LNode* next;
};

struct HashNode{
    struct LNode** Array;

};

struct LNode* NewNode(int data){
struct LNode* node=(struct LNode*)malloc(sizeof(struct LNode));
node->data=data;
node->next=NULL;
}

void Insert(struct HNode* root,int data){
if(root->next==NULL){
root->next=NewNode(data);
}
else{
struct LNode* tmpNode=root->next;
while(tmpNode->next){
tmpNode=tmpNode->next;
}
tmpNode->next=NewNode(data);

}
root->count++;

}

void Traverse(struct HNode* root){
struct LNode* tmpNode=root->next;
while(tmpNode){
printf("%d --> ",tmpNode->data);
tmpNode=tmpNode->next;
}
}



void Merge(struct HNode* root,struct HNode* root1,struct HNode* root2){

struct LNode* tmpNode=root->next;
struct LNode* tmpNode1=root1->next;


struct LNode** lastNode=&root2->next;
struct LNode* newNode;
while(1){

if(!tmpNode){
(*lastNode)=tmpNode1;
break;
}
else if(!tmpNode1){
(*lastNode)=tmpNode;
break;
}
else if(tmpNode->data<=tmpNode1->data){
newNode=(struct LNode*)malloc(sizeof(struct LNode));
newNode->data=tmpNode->data;
newNode->next=NULL;
(*lastNode)=newNode;
tmpNode=tmpNode->next;
}
else{
newNode=(struct LNode*)malloc(sizeof(struct LNode));
newNode->data=tmpNode1->data;
newNode->next=NULL;
(*lastNode)=newNode;
tmpNode1=tmpNode1->next;
}

(lastNode)=&(*lastNode)->next;

}
}


int main(){
int i;
int data;
struct HNode* root=(struct HNode* )malloc(sizeof(struct HNode));
root->count=0;
root->next=NULL;
struct HNode* root1=(struct HNode* )malloc(sizeof(struct HNode));
root1->count=0;
root1->next=NULL;
struct HNode* root2=(struct HNode* )malloc(sizeof(struct HNode));
root2->count=0;
root2->next=NULL;
int n;
printf("\nEnter data for first lsit \n");
getch();
for(i=0;i<6;i++){
printf("\nenter data for %dth node : ",i);
scanf("%d",&data);
Insert(root,data);
}

printf("\n%d Nodes inserted...",i);
getch();

printf("\nEnter to traverse..\n\n");
getch();
Traverse(root);
getch();
printf("\nEnter data for second list :\n");
getch();
for(i=0;i<6;i++){
printf("\nenter data for %dth node : ",i);
scanf("%d",&data);
Insert(root1,data);
}

printf("\n%d Nodes inserted...",i);
getch();

printf("\nEnter to traverse..\n\n");
getch();
Traverse(root1);
getch();
printf("\nMerging two list : \n");
Merge(root,root1,root2);
Traverse(root2);
getch();
return 0;
}
