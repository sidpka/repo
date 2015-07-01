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

struct LNode* CreateStack(){

struct LNode* root=(struct LNode*)malloc(sizeof(struct LNode));
root->next=NULL;

return root;
}

void Push(struct LNode* root,int data){
    struct LNode* newNode=(struct LNode*)malloc(sizeof(struct LNode));
if(root->next==NULL){
newNode->data=data;
newNode->next=NULL;
root->next=newNode;
}
else{
 struct LNode* tmpNode=root->next;
 newNode->data=data;
 root->next=newNode;
 newNode->next=tmpNode;

}
}

int Pop(struct LNode* root){
if(!root->next){
return -1;
}else{
struct LNode* tmpNode=root->next;
root->next=tmpNode->next;
return tmpNode->data;
}
}

int CheckPalindrome(struct HNode* root){
struct LNode* stackRoot=CreateStack();
struct LNode* tmpNode=root->next;
while(tmpNode){
Push(stackRoot,tmpNode->data);
tmpNode=tmpNode->next;
}

tmpNode=root->next;
int tmpData;
int count=0;
while(tmpNode){
    tmpData=Pop(stackRoot);
    count++;
if(tmpNode->data!=tmpData){
    printf("\nNot matched here : tmpNode data : %d || pop data : %d on iteration : %d" ,tmpNode->data,tmpData,count);
return 0;
}
tmpNode=tmpNode->next;
}
return 1;
}
struct LNode* FindMid(struct HNode* root,int l){
struct LNode* tmpNode=root->next;
int count=0;
while(tmpNode && count<l){
tmpNode=tmpNode->next;
count++;
}
return tmpNode;
}
struct LNode* DoReverse(struct LNode* root){
struct LNode* current=root->next;
struct LNode* prev=NULL;
struct LNode* next;

while(current){
next=current->next;
current->next=NULL;
prev=current;
current=next;
}
return prev;
}
int CheckPalindromeReverse(struct HNode* root){
int len=0;
struct LNode* tmpNode=root->next;
while(tmpNode){
len++;
tmpNode=tmpNode->next;
}

if(len&1){
struct LNode* mid=FindMid(root,len/2 +1);
mid->next=DoReverse(mid);
tmpNode=root->next;
struct LNode* tp=mid->next;
while(tmpNode!=mid && tp!=NULL){

if(tmpNode->data!=tp->data){
return 0;
}
tmpNode=tmpNode->next;
tp=tp->next;
}
}
return 1;
}


void DelFirst(struct HNode** root){
    if(!(*root)->next){
    return;
    }
struct LNode* tmpNode=(*root)->next;
(*root)->next=tmpNode->next;
free(tmpNode);
}

void InsertBeginning(struct HNode* root,int data){

if(root->next==NULL){
root->next=(struct LNode*)malloc(sizeof(struct LNode));
root->next->data=data;
root->next->next=NULL;
}
else{
struct LNode* newNode=(struct LNode*)malloc(sizeof(struct LNode));
newNode->data=data;
struct LNode* tmpNode=root->next;
newNode->next=tmpNode;
root->next=newNode;
}
root->count++;
}

void InsertAfter(struct LNode* prev,int data){

if(prev==NULL){
return;
}
struct LNode* np=(struct LNode*)malloc(sizeof(struct LNode));
np->data=data;
np->next=prev->next;
prev->next=np;

}
void Del(struct HNode* root,int data){

if(!root->next){
return;
}

struct LNode* tmpNode=root->next;
struct LNode* prv;

if(tmpNode!=NULL && tmpNode->data==data){
root->next=tmpNode->next;
free(tmpNode);
return;
}

while(tmpNode!=NULL && tmpNode->data!=data){
prv=tmpNode;
tmpNode=tmpNode->next;
}
prv->next=tmpNode->next;
free(tmpNode);
}

struct LNode* FindNth(struct HNode* root,int n){
int count =1;
struct LNode* tmpNode=root->next;
while(count!=n && tmpNode!=NULL){
    count++;
tmpNode=tmpNode->next;
}
if(count!=n){
return NULL;
}
return tmpNode;
}

void DelPointer(struct LNode* gn){
struct LNode* tmpNode=gn->next;
gn->data=tmpNode->data;
gn->next=tmpNode->next;
free(tmpNode);


}
struct LNode* MiddleOfLink(struct HNode* root){
struct LNode* slowerLink=root->next;
struct LNode* fasterLink=root->next;

while(fasterLink!=NULL && fasterLink->next!=NULL){

fasterLink=fasterLink->next->next;
slowerLink=slowerLink->next;
}

return slowerLink;
}
struct LNode* MiddleLink(struct HNode* root){
struct LNode* tmpNode=root->next;
struct LNode* mid=root->next;
int count=0;
while(tmpNode){
if(count& 1){
mid=mid->next;
}
count++;
tmpNode=tmpNode->next;
}

return mid;
}

struct LNode* NthFromEnd(struct HNode* root,int n){
struct LNode* refLink=root->next;
struct LNode* mainLink=root->next;
int count=n;
while(refLink){
if(count){
count--;
refLink=refLink->next;
continue;
}
refLink=refLink->next;
mainLink=mainLink->next;
}
return mainLink;
}
void DeleteLL(struct HNode* root){

struct LNode* tmpNode=root->next;
while(root->next){
tmpNode=root->next;
root->next=tmpNode->next;
free(tmpNode);
}

free(root);


}

int CountOccurance(struct HNode* root,int n){
struct LNode* tmpNode=root->next;
int count=0;
while(tmpNode){
if(tmpNode->data==n){
count++;
}
tmpNode=tmpNode->next;
}
return count;
}

void Reverse(struct HNode* root){

struct LNode* current =root->next;
struct LNode* prev=NULL;
struct LNode* nextNode;

while(current){

nextNode=current->next;
current->next=prev;
prev=current;
current=nextNode;



}



root->next=prev;
}

void FindCycle(struct HNode* root){
struct LNode* fastP=root->next;
struct LNode* slowP=root->next;

while(fastP && slowP && fastP->next){
fastP=fastP->next->next;
slowP=slowP->next;
if(fastP==slowP){
printf("\nLoop found");
return;
}
}

printf("\nLoop not found");

}

int main(){
int i;
int data;
struct HNode* root=(struct HNode* )malloc(sizeof(struct HNode));
root->count=0;
root->next=NULL;
int n;
for(i=0;i<5;i++){
printf("\nenter data for %dth node : ",i);
scanf("%d",&data);
Insert(root,data);
}
//InsertAfter(root->next,5);
printf("\n%d Nodes inserted...",i);
getch();

//printf("\nEnter n find cycle : \n");
//getch();
//FindCycle(root);
//getch();
printf("\nEnter to traverse..\n\n");
getch();
Traverse(root);
getch();


//printf("\nEnter to reverse the L :\n");
//Reverse(root);
//Traverse(root);
//getch();
printf("\nEnter to check if palindrome \n");
getch();
if(CheckPalindromeReverse(root)){
printf("\nPalindrome");
}
else{
printf("\nNot a plaindrome");
}
getch();
printf("\nMiddle node is : %d",MiddleLink(root)->data);
printf("\n\n%d nodes found ... ",root->count);
getch();
int x;
printf("\nEnter n to see nth node from end : ");

scanf("%d",&x);
struct LNode* tNode=NthFromEnd(root,x);
if(tNode){
printf("\n%dth node from end is : %d",x,tNode->data);
}
else{
printf("\nSorry");
}
getch();
printf("\nEnter the number to count occurance :  ");
scanf("%d",&x);
printf("\n%d occured for : %d times",x,CountOccurance(root,x));
getch();
printf("\nDeleting LL \n\n");
//DeleteLL(root);
getch();
printf("\nFind nth node from start \nEnter n : ");
scanf("%d",&n);
struct LNode* node=FindNth(root,n);
if(node){
printf("\n%dth node is : %d",n,node->data);
}
else{
printf("\n%dth node doesnot exist....\n\n",n);
}
getch();

printf("\nEnter to delete by pointer.. \n");
struct LNode* tmpNode=root->next;
tmpNode=tmpNode->next;
DelPointer(tmpNode);
Traverse(root);
getch();
/*
printf("\nEnter to delete node : ");
scanf("%d",&data);
Del(root,data);
getch();
*/
printf("\nEnter to delete first elmnt : \n");
DelFirst(&root);
getch();
Traverse(root);
getch();
return 0;
}
