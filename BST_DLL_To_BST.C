#include<stdio.h>
#include<stdlib.h>
#include<conio.h>



struct TreeNode{
int data;
struct TreeNode* left,*right;
};
typedef struct TreeNode TNode;

struct LinkedList{
int data;
struct LinkedList* next;
struct LinkedList* prev;
};

typedef struct LinkedList LNode;


TNode* NewNode(int data){
TNode* newNode=(TNode*)malloc(sizeof(TNode));
newNode->data=data;
newNode->right=NULL;
newNode->left=NULL;
return newNode;
}

void Insert(TNode** root,int data){
if(!(*root)){
(*root)=NewNode(data);
}else{
if((*root)->data>data){
Insert(&(*root)->left,data);
}else{
Insert(&(*root)->right,data);
}
}
}


int Search(TNode* root,int data){
if(!root){
return 0;
}
if(root->data==data){
return 1;
}
else if(root->data> data){
return Search(root->left,data);
}else{
return Search(root->right,data);
}
}


void InsertList(TNode** head,int data){

TNode* tmpNode=(TNode*)malloc(sizeof(TNode));
tmpNode->data=data;
tmpNode->left=NULL;

if(!(*head)){
tmpNode->right=NULL;
(*head)=tmpNode;
return;
}
(*head)->left=tmpNode;
tmpNode->right=(*head);
(*head)=tmpNode;
}

void TraverseList(TNode* head){
if(!head){
return;
}
while(head){
printf("%d  ",head->data);
head=head->right;
}
}

LNode* GetMid(LNode** head){
if(!head){
return NULL;
}

LNode* fastPtr=(*head);
LNode* slowPtr=(*head);
LNode* prev=slowPtr;
while(fastPtr && fastPtr->next){
fastPtr=fastPtr->next->next;
prev=slowPtr;
slowPtr=slowPtr->next;
}



return prev;
}

TNode* ConstructTree(LNode** head){

if(!(*head)){
return NULL;
}
LNode* mid=GetMid(head);
if(mid){
TNode* root=(TNode*)malloc(sizeof(TNode));
LNode* tmpNode;
if(mid->next==NULL){
tmpNode=mid;
root->left=NULL;
root->right=NULL;
}else{
tmpNode=mid->next;
mid->next=NULL;
root->right=ConstructTree(&tmpNode->next);
tmpNode->next=NULL;
root->left=ConstructTree(head);
}
root->data=tmpNode->data;

return root;
}else{
return NULL;
}

}

void InOrder(TNode* root){
if(!root){
return;
}
InOrder(root->left);
printf("%d  ",root->data);
InOrder(root->right);
}

TNode* CreateBST(LNode** head,int n){

if(n<=0){
return NULL;
}

TNode* left=CreateBST(head,n/2);

TNode* root=(TNode*)malloc(sizeof(TNode));
root->data=(*head)->data;
root->left=left;
(*head)=(*head)->next;
root->right=CreateBST(head,n-(n/2)-1);
return root;

}


TNode* CreateTree_From_DLL(TNode** head,int n){

if(n<=0){
return NULL;
}
TNode* left=CreateTree_From_DLL(head,n/2);
TNode* root=(*head);
root->left=left;
(*head)=(*head)->right;
root->right=CreateTree_From_DLL(head,n-(n/2)-1);

return root;
}

int main(){
printf("\nEnter the no of nodes you want to insert in LL: ");
int n;
scanf("%d",&n);
int i;
int data;
//LNode* head=NULL;
TNode* head=NULL;
for(i=0;i<n;i++){
printf("\nEnter data :  ");
scanf("%d",&data);
InsertList(&head,data);
}

printf("\nList created\n");
getch();
printf("\nPress enter to traverse list\n");
getch();
TraverseList(head);
getch();
printf("\nPress enter to create tree \n\n");
getch();
TNode* root=CreateTree_From_DLL(&head,n);
printf("\nTree created\n");
printf("\nPress enter to traverse tree inorder\n\n");
getch();
InOrder(root);
getch();

return 0;
}
