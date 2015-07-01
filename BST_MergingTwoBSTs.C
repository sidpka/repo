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

void PickNodes(TNode* root,int* buffer,int* i){
if(!root){
return;
}
PickNodes(root->left,buffer,i);
buffer[(*i)++]=root->data;
PickNodes(root->right,buffer,i);

}

int* MergeBuffers(int* buffer1,int* buffer2,int n,int m){
int* finalArray=(int*)malloc(sizeof(int)*(n+m));
int i=0,j=0,k=0;

while(i<n && j<m){
if(buffer1[i]<buffer2[j]){
finalArray[k++]=buffer1[i++];
}else{
finalArray[k++]=buffer2[j++];
}
}

while(i<n){
finalArray[k++]=buffer1[i++];
}

while(j<m){
finalArray[k++]=buffer2[j++];
}

return finalArray;

}


TNode* MergeBST(int* finalArray,int start,int end){
if(start>end){
return NULL;
}

int mid=(start+end)/2;

TNode* root=NewNode(finalArray[mid]);
root->left=MergeBST(finalArray,start,mid-1);
root->right=MergeBST(finalArray,mid+1,end);

return root;

}


TNode* GetMergedBST(TNode* root1,TNode* root2,int n,int m){
if(!root1){
return root2;
}
if(!root2){
return root1;
}

int* buffer1=(int*)malloc(sizeof(int)*n);
int ind=0;
PickNodes(root1,buffer1,&ind);

int* buffer2=(int*)malloc(sizeof(int)*m);
ind=0;
PickNodes(root2,buffer2,&ind);
int* FinalArray=MergeBuffers(buffer1,buffer2,n,m);

return MergeBST(FinalArray,0,m+n-1);
}

void InOrder(TNode* root){

if(!root){
return;
}
InOrder(root->left);
printf("%d  ",root->data);
InOrder(root->right);

}

int main(){
printf("\nEnter the no of nodes you want to insert in BST1  : ");
int n;
scanf("%d",&n);
int i,data;
TNode* root=NULL;
for(i=0;i<n;i++){
printf("\nEnter data for %d node : ",i);
scanf("%d",&data);
Insert(&root,data);
}
printf("\n%d nodes inserted in BST1\n",i);
getch();
printf("\nEnter the no of nodes you want to insert in BST2  : ");
int m;
scanf("%d",&m);
TNode* root1=NULL;
for(i=0;i<m;i++){
printf("\nEnter data for %d node : ",i);
scanf("%d",&data);
Insert(&root1,data);
}
printf("\n%d nodes inserted in BST2\n",i);

printf("\nPress enter to merge two trees\n");
getch();

TNode* root2=GetMergedBST(root,root1,n,m);
printf("\nBSTs are mrg\nPress enter to traverse\n");
getch();
InOrder(root2);
getch();
getch();

return 0;
}
