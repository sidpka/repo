#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define Load_Factor 1
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

void AddList(struct HNode* root,struct HNode* root1,struct HNode* root2){
struct LNode* np;
int sum;
int cr=0;
struct LNode* tmpNode=root->next;
struct LNode* tmpNode1=root1->next;

struct LNode** lastNode=&(root2->next);

while(1){

if(!tmpNode && !tmpNode1){
    if(cr){

np=(struct LNode*)malloc(sizeof(struct LNode));
np->data=cr;
np->next=NULL;
(*lastNode)=np;

    }
break;
}
else if(!tmpNode){
sum=(tmpNode1->data)+cr ;
np=(struct LNode*)malloc(sizeof(struct LNode));
np->data=(sum)%10;
np->next=NULL;
cr=(sum)/10;
(*lastNode)=np;
tmpNode1=tmpNode1->next;
}
else if(!tmpNode1){
sum=(tmpNode->data)+cr;
np=(struct LNode*)malloc(sizeof(struct LNode));
np->data=(sum)%10;
np->next=NULL;
cr=(sum)/10;
(*lastNode)=np;
tmpNode=tmpNode->next;
}
else{
sum=(tmpNode->data)+(tmpNode1->data)+cr;
np=(struct LNode*)malloc(sizeof(struct LNode));
np->data=(sum)%10;
np->next=NULL;
cr=(sum)/10;
(*lastNode)=np;
tmpNode=tmpNode->next;
tmpNode1=tmpNode1->next;
}
lastNode=&(*lastNode)->next;
}

}

void FindTriplet(struct HNode* root,struct HNode* root1,struct HNode* root2,int m){
struct LNode* tmpNode=root->next;
struct LNode* tmpNode1=root1->next;
struct LNode* tmpNode2=root2->next;
int sum;
while(tmpNode){
tmpNode1=root1->next;
tmpNode2=root2->next;
while(tmpNode1 && tmpNode2){
sum=tmpNode->data+tmpNode1->data+tmpNode2->data;

if(sum==m){
printf("\nTriplet :   %d\t%d\t%d",tmpNode->data,tmpNode1->data,tmpNode2->data);
break;
}
else if(sum<m){
tmpNode1=tmpNode1->next;
}
else{
tmpNode2=tmpNode2->next;
}

}
tmpNode=tmpNode->next;
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
for(i=0;i<3;i++){
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
for(i=0;i<3;i++){
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
printf("\nEnter data for third list :\n");
getch();
for(i=0;i<3;i++){
printf("\nenter data for %dth node : ",i);
scanf("%d",&data);
Insert(root2,data);
}

printf("\n%d Nodes inserted...",i);
getch();

printf("\nEnter to traverse..\n\n");
getch();
Traverse(root2);
getch();

printf("\nEnter a number to see triplet : ");
int m ;
scanf("%d",&m);
FindTriplet(root,root1,root2,m);

return 0;
}
