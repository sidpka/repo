
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct AVLNode{

int data;
int size;
int height;
struct AVLNode* left;
struct AVLNode* right;
};
typedef struct AVLNode ANode;


int Height(ANode* node){
    if(node==NULL){
    return 0;
    }
return node->height;
}

int Balance(ANode* node){
if(node==NULL){
return 0;
}
return Height(node->left)-Height(node->right);
}

int max(int a,int b){
return a>b?a:b;
}

ANode* NewNode(int data){
ANode* tmpNode=(ANode*)malloc(sizeof(ANode));
tmpNode->height=1;
tmpNode->left=NULL;
tmpNode->right=NULL;
tmpNode->size=1;
tmpNode->data=data;

return tmpNode;
}


int FindSize(ANode* node){

if(node==NULL){
return 0;
}

return node->size;
}


ANode* LeftRotate(ANode* root){
ANode* tmp1=root->right;
ANode* tmp2=tmp1->left;

tmp1->left=root;
root->right=tmp2;

root->height=max(Height(root->left),Height(root->right))+1;
tmp1->height=max(Height(tmp1->left),Height(tmp1->right))+1;
root->size=FindSize(root->left)+FindSize(root->right)+1;
tmp1->size=FindSize(tmp1->left)+FindSize(tmp1->right)+1;

return tmp1;
}

ANode* RightRotate(ANode* root){
//printf("\nEntering right rotate");
ANode* tmp1=root->left;
ANode* tmp2=tmp1->right;

tmp1->right=root;
root->left=tmp2;

root->height=max(Height(root->left),Height(root->right))+1;
tmp1->height=max(Height(tmp1->left),Height(tmp1->right))+1;
//printf("\nLeaving right rotate");
root->size=FindSize(root->left)+FindSize(root->right)+1;
tmp1->size=FindSize(tmp1->left)+FindSize(tmp1->right)+1;

//printf("\nLeaving right rotate");
return tmp1;
}



ANode* InsertAVL(ANode* root,int data,int* count){
if(!root){
return NewNode(data);
}

if(root->data>data){
root->left=InsertAVL(root->left,data,count);

}else{
root->right=InsertAVL(root->right,data,count);
(*count)+=FindSize(root->left)+1;
}

root->height=max(Height(root->left),Height(root->right))+1;
root->size=FindSize(root->left)+FindSize(root->right)+1;

int bf=Balance(root);
//printf("\Here");
if(bf>1 && data<root->left->data){
return RightRotate(root);
}

if(bf>1 && data>root->left->data){
root->left=LeftRotate(root->left);
return RightRotate(root);
}

if(bf<-1 && data> root->right->data){
return LeftRotate(root);
}

if(bf<-1 && data<root->right->data){
root->right=RightRotate(root->right);
return LeftRotate(root);
}

return root;
}


void CountMin(int* arr,int n){
int* count=(int*)calloc(n,sizeof(int));

int i;
ANode* root=NULL;
for(i=n-1;i>=0;i--){
root=InsertAVL(root,arr[i],&count[i]);
}

for(i=0;i<n;i++){
printf("%d  ",count[i]);
}

}

int main(){

int arr[]={10, 6, 15, 20, 30, 5, 7};

int n=sizeof(arr)/sizeof(arr[0]);

printf("\Press enter to find minimum count on right side :\n\n\n ");
getch();
CountMin(arr,n);
getch();
return 0;
}
