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


void Reverse(struct LNode** root){
struct LNode* current=*root;
struct LNode* prev=NULL;
struct LNode* next;

while(current){
next=current->next;
current->next=prev;
prev=current;
current=next;
}
*root=prev;
}
int Compare(struct LNode* firstPart,struct LNode* secondPart){

struct LNode* tmpNode1=firstPart;
struct LNode* tmpNode2=secondPart;
while(tmpNode1 && tmpNode2){
if(tmpNode1->data==tmpNode2->data){
tmpNode1=tmpNode1->next;
tmpNode2=tmpNode2->next;
}
else{
return 0;
}
}

return 1;
}
int Palindrome(struct HNode* root){


struct LNode* slowPtr=root->next;
struct LNode* fastPtr=root->next;
struct LNode* slowPtrPrev;
struct LNode* mid=NULL;
struct LNode* secondPart;
while(fastPtr && fastPtr->next){
fastPtr=fastPtr->next;
fastPtr=fastPtr->next;
slowPtrPrev=slowPtr;
slowPtr=slowPtr->next;
}
//Odd
if(fastPtr){
mid=slowPtr;
slowPtr=slowPtr->next;
}
secondPart=slowPtr;
slowPtrPrev->next=NULL;
Reverse(&secondPart);
/*
if(Compare(root->next,secondPart)){
return 1;
}
return 0;
*/

Reverse(&secondPart);
if(mid){

slowPtrPrev->next=mid;
mid->next=secondPart;

}
else{
slowPtrPrev->next=secondPart;
}

}

void SortedInsert(struct HNode* root,int data){
struct LNode* tmpNode=root->next;
struct LNode* prevNode=root->next;
struct LNode* newNode=(struct LNode*)malloc(sizeof(struct LNode));

newNode->data=data;

if(root->next==NULL || root->next->data >=data){
newNode->next=root->next;
root->next=newNode;
}
else{

while(tmpNode){

if(tmpNode->data >=data){
break;
}
prevNode=tmpNode;
tmpNode=tmpNode->next;
}


newNode->next=prevNode->next;
prevNode->next=newNode;

}
}

int FindLength(struct HNode* root){
int len=0;
struct LNode* tmpNode=root->next;
while(tmpNode){
    len++;
tmpNode=tmpNode->next;

}
return len;
}

struct LNode* FindIntersectionPoint(struct HNode* root1,struct HNode* root2){

int len1=FindLength(root1);
int len2=FindLength(root2);
struct LNode* firstList=root1->next;
struct LNode* secondList=root2->next;
int i;
if(len1>len2)
for(i=0;i<(len1-len2);i++){
firstList=firstList->next;
}
if(len1<len2)
for(i=0;i<(len2-len1);i++){
secondList=secondList->next;
}

while(firstList && secondList){
if(firstList==secondList){
return firstList;
}
firstList=firstList->next;
secondList=secondList->next;
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
int n;
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

struct LNode* tNode=root->next;
while(tNode->next){
tNode=tNode->next;
}
struct LNode* tNode1=root1->next;
while(tNode1->next){
tNode1=tNode1->next;
}
tNode1->next=tNode;
for(i=0;i<4;i++){
printf("\nEnter data : ");
scanf("%d",&data);
struct LNode* np=(struct LNode*)malloc(sizeof(struct LNode));
np->data=data;
np->next=NULL;
tNode->next=np;
tNode=tNode->next;
}

printf("\nEnter to traverse first list : \n");
getch();
Traverse(root);
getch();
printf("\nEnter to traverse second list : \n\n");
getch();
Traverse(root1);
getch();

printf("\nEnter to find intersecting node : ");
getch();
struct LNode* iNode=FindIntersectionPoint(root,root1);
printf("\nIntersection point is : %d",iNode->data);



Palindrome(root);
printf("\n");
Traverse(root);
printf("\nEnter to see if palindrome ...");
getch();
if(Palindrome(root)){
printf("\nPalindrome");
}
else{

printf("\nNot Palindrome");

}

}
