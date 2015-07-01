#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct AVLTree{

int data;
int count;
int visited;
int height;
struct AVLTree* left;
struct AVLTree* right;

};

typedef struct AVLTree TNode;

TNode* NewNode(int data){

TNode* tmpNode=(TNode*)malloc(sizeof(TNode));
tmpNode->data=data;
tmpNode->count=1;
tmpNode->visited=0;
tmpNode->height=1;
tmpNode->left=NULL;
tmpNode->right=NULL;

return tmpNode;

}


int Height(TNode* root){
if(!root){
return 0;
}

return root->height;

}

int Balance(TNode* root){
if(!root){
return 0;
}

return Height(root->left)-Height(root->right);

}

int max(int a,int b){

return a>b?a:b;

}

TNode* LeftRotate(TNode* root){

TNode* X=root->right;
TNode* Y=X->left;

X->left=root;
root->right=Y;

root->height=max(Height(root->left),Height(root->right))+1;
X->height=max(Height(X->left),Height(X->right))+1;

return X;
}

TNode* RightRotate(TNode* root){

TNode* X=root->left;
TNode* Y=X->right;

X->right=root;
root->left=Y;

root->height=max(Height(root->left),Height(root->right))+1;
X->height=max(Height(X->left),Height(X->right))+1;

return X;


}



TNode* Insert(TNode* root,int data){


if(!root){
return NewNode(data);
}

if(root->data==data){
root->count++;
}

else if(root->data>data){
root->left=Insert(root->left,data);
}else{
root->right=Insert(root->right,data);
}

root->height=max(Height(root->left),Height(root->right))+1;

int bf=Balance(root);

if(bf > 1 && data<root->left->data){
return RightRotate(root);
}

if(bf>1 && data>root->left->data){
    root->left=LeftRotate(root->left);
return RightRotate(root);
}

if(bf<-1 && data>root->right->data){
return LeftRotate(root);
}

if(bf<-1 && data<root->right->data){
root->right=RightRotate(root->right);
return LeftRotate(root);
}


return root;
}


void Traverse(TNode* root){

if(!root){
return;
}

Traverse(root->left);
int i;

for(i=0;i<root->count;i++){
printf("%d  ",root->data);
}

Traverse(root->right);

}


void Update(TNode* root,int key,int* buffer,int* index){

if(!root){
return;
}

if(key<root->data){
Update(root->left,key,buffer,index);
}

else if(root->data==key){
int i;

for(i=0;i<root->count;i++){
buffer[(*index)++]=root->data;
}
root->visited=1;
return;
}

else{
Update(root->right,key,buffer,index);
}


}

void UpdateLeftOvers(TNode* root,int* buffer,int* index){

if(!root){
return;
}

UpdateLeftOvers(root->left,buffer,index);

if(root->visited==0){

int i;

for(i=0;i<root->count;i++){
buffer[(*index)++]=root->data;
}
root->visited=1;
}

UpdateLeftOvers(root->right,buffer,index);



}


void Sort(int* A,int n,int* B,int m){

int i;
TNode* root=NULL;
for(i=0;i<n;i++){
root=Insert(root,A[i]);
//printf("\nhere");
}
/*
Traverse(root);

getch();
*/

int* output=(int*)malloc(sizeof(int)*n);
int index=0;

for(i=0;i<m;i++){
Update(root,B[i],output,&index);
}
/*
for(i=0;i<n;i++){
printf("%d  ",output[i]);
}

getch();
*/

UpdateLeftOvers(root,output,&index);

/*
for(i=0;i<n;i++){
printf("%d  ",output[i]);
}

getch();
*/
for(i=0;i<n;i++){
A[i]=output[i];
}

free(output);

}

int main(){

int arr1[]={2,1,2,5,7,1,9,3,6,8,8};
int n=sizeof(arr1)/sizeof(arr1[0]);

int arr2[]={2,1,8,3};

int m=sizeof(arr2)/sizeof(arr2[0]);

Sort(arr1,n,arr2,m);

printf("\nSorted result of arr1 with respect to order of arr2\n");
int i;

for(i=0;i<n;i++){
printf("%d  ",arr1[i]);
}






return 0;
}
