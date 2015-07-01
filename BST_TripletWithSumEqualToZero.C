#include<stdio.h>
#include<stdlib.h>
#include<conio.h>



struct TreeNode{
int data;
struct TreeNode* left,*right;
};
typedef struct TreeNode TNode;

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

void InorderTraversal(TNode* root){

if(!root){
return;
}

InorderTraversal(root->left);
printf("%d  ",root->data);
InorderTraversal(root->right);
}

void GetSortedArray(TNode* root,int* buffer,int* index){
if(!root){
return;
}

GetSortedArray(root->left,buffer,index);
buffer[(*index)++]=root->data;
GetSortedArray(root->right,buffer,index);

}


int CheckIfTripletPresent(int* buffer,int n){

int i;

int l,r;

for(i=0;i<n-2;i++){

l=i+1;
r=n-1;
while(l<r){
if(buffer[i]+buffer[l]+buffer[r]==0){
return 1;
}else if(buffer[i]+buffer[l]+buffer[r]< 0){
l++;
}else{
r--;
}
}


}

return 0;
}

void ConvertToDLL(TNode* root,TNode** head,TNode** tail){
if(!root){
return;
}

if(root->left){

ConvertToDLL(root->left,&(*head),&(*tail));

}


root->left=(*tail);

if(*tail){
(*tail)->right=root;
}else{
(*head)=root;
}

(*tail)=root;

if(root->right){
ConvertToDLL(root->right,&(*head),&(*tail));
}

}

int IsPresentInDLL(TNode* head,TNode* tail,int data){

while(head!=tail){
if(head->data+tail->data==data){
return 1;
}else if(head->data+tail->data < data){
head=head->right;
}else{
tail=tail->left;
}
}
return 0;
}


int CheckTriplet(TNode* root){

TNode* head=NULL;
TNode* tail=NULL;
ConvertToDLL(root,&head,&tail);
while(head->right!=tail && head->data < 0){
if(IsPresentInDLL(head->right,tail,(-1)*head->data)){
return 1;
}else{
head=head->right;
}
}

return 0;

}

int main(){
printf("\nEnter the no of nodes you want to insert : ");
int n;
scanf("%d",&n);
int i,data;
TNode* root=NULL;
for(i=0;i<n;i++){
printf("\nEnter data for %d node : ",i);
scanf("%d",&data);
Insert(&root,data);
}
printf("\n%d nodes inserted in BST\n");

getch();
printf("\nPress enter to traverse \n\n: ");
getch();
InorderTraversal(root);
getch();
int* buffer=(int*)malloc(sizeof(int)*n);
int index=0;
GetSortedArray(root,buffer,&index);

printf("\nSorted array is : \n\n");
getch();
for(i=0;i<n;i++){
printf("%d  ",buffer[i]);
}
/*
int result=CheckIfTripletPresent(buffer,n);
if(result){
printf("\nTriplet found");
}else{
printf("\nTriplet not found");
}
*/

//Another method

int result=CheckTriplet(root);
if(result){
printf("\n\n\nYes");
}else{
printf("\n\nNo");
}
return 0;
}
