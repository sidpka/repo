#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct BST{
int data;
int freq;
struct BST* left;
struct BST* right;
};
typedef struct BST TNode;

TNode* NewNode(int data){

TNode* tmpNode=(TNode*)malloc(sizeof(TNode));
tmpNode->data=data;
tmpNode->freq=1;
tmpNode->left=NULL;
tmpNode->right=NULL;

return tmpNode;

}


TNode* Insert(TNode* root,int data){

if(!root){
return NewNode(data);
}

if(root->data==data){
root->freq++;
}else if(root->data>data){
root->left=Insert(root->left,data);
}else{
root->right=Insert(root->right,data);
}


return root;
}


void PrintElementsWithFreqMoreThanCount(TNode* root,int count){

if(!root){
return;
}

PrintElementsWithFreqMoreThanCount(root->left,count);
if(root->freq>count){
printf("%d  ",root->data);
}

PrintElementsWithFreqMoreThanCount(root->right,count);

}


void FindN_K_Freq(int* arr,int n,int k){

TNode* root=NULL;

int i;

for(i=0;i<n;i++){
root=Insert(root,arr[i]);
}

int count=n/k;

//printf("%d",count);
printf("\nElements with frequency greater than [n/k= %d] are : \n\n",count);
PrintElementsWithFreqMoreThanCount(root,count);

}

int main(){


int arr[]={3,1,2,2,1,2,3,3,4};
int n=sizeof(arr)/sizeof(arr[0]);
int k=4;

FindN_K_Freq(arr,n,k);






return 0;
}
