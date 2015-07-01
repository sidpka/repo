#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct BST{

int data;
int height;
struct BST* left,*right;
};

typedef struct BST TNode;

TNode* NewNode(int data){

TNode* tmpNode=(TNode*)malloc(sizeof(TNode));
tmpNode->data=data;
tmpNode->height=1;
tmpNode->left=NULL;
tmpNode->right=NULL;

return tmpNode;

}

int max(int a,int b){
return a>b?a:b;
}

int Height(TNode* root){
if(!root){
return 0;
}

return root->height;
}

int BalanceFactor(TNode* root){
if(!root){
return 0;
}

return Height(root->left)-Height(root->right);
}

TNode* LeftRotate(TNode* root){

TNode* x=root->right;
TNode* y=x->left;

x->left=root;
root->right=y;

root->height=max(Height(root->left),Height(root->right))+1;
x->height=max(Height(x->left),Height(x->right))+1;

return x;

}

TNode* RightRotate(TNode* root){

TNode* x=root->left;
TNode* y=x->right;

x->right=root;
root->left=y;

root->height=max(Height(root->left),Height(root->right))+1;
x->height=max(Height(x->left),Height(x->right))+1;

return x;



}

TNode* Insert(TNode* root,int data){

if(!root){
return NewNode(data);
}

if(root->data>data){
root->left=Insert(root->left,data);
}else{
root->right=Insert(root->right,data);
}

root->height=max(Height(root->left),Height(root->right))+1;

int bf=BalanceFactor(root);

if(bf>1){

if(data<root->left->data){
return RightRotate(root);
}else if(data>=root->left->data){
root->left=LeftRotate(root->left);
return RightRotate(root);
}

}

if(bf<-1){

if(data>root->right->data){
return LeftRotate(root);
}else if(data<root->right->data){
root->right=RightRotate(root->right);
return LeftRotate(root);
}
}

return root;
}

int FindFloor(TNode* root,int data){

if(!root){
return 0;
}

int right;

if(root->data==data){
return root->data;
}else if(root->data<data){

right=FindFloor(root->right,data);
//printf("\nright : %d",right);
if(right){
return right;
}else{
return root->data;
}
}else{
return FindFloor(root->left,data);
}

}

void FindIncreasingTripletWithMaxProduct(int* arr,int n){

//LSL Largest Smaller Left
//LGR Largest Greater Right

int* LSL=(int*)malloc(sizeof(int)*n);
int* LGR=(int*)malloc(sizeof(int)*n);

TNode* root=NULL;
int i;

for(i=0;i<n;i++){
LSL[i]=FindFloor(root,arr[i]);
root=Insert(root,arr[i]);
}

/*
printf("\nLSL\n");
for(i=0;i<n;i++){
printf("%d  ",LSL[i]);
}
*/

int max=0;

for(i=n-1;i>=0;i--){

if(max<arr[i]){
max=arr[i];
LGR[i]=0;
}else{
LGR[i]=max;
}

}

/*
printf("\nLGR\n");

for(i=0;i<n;i++){
printf("%d  ",LGR[i]);
}
*/

max=0;
int tmpMax;
int maxIndex;
for(i=0;i<n;i++){
   tmpMax=arr[i]*LSL[i]*LGR[i];
   if(tmpMax>max){
   max=tmpMax;
   maxIndex=i;
   }
}

printf("\nIncreasing Subsequence : %d %d %d",LSL[maxIndex],arr[maxIndex],LGR[maxIndex]);


}

int main(){


int arr[]={6,7,8,1,2,3,9,10};

int n=sizeof(arr)/sizeof(arr[0]);

FindIncreasingTripletWithMaxProduct(arr,n);







return 0;
}
