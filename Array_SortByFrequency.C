#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct BST{

int data;
int freq;
struct BST* left,*right;

};
typedef struct BST TNode;

struct dataFreq{
int data;
int count;
};

typedef struct dataFreq dFreq;

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

void Traverse(TNode* root){

if(!root){
return;
}

Traverse(root->left);
printf("\ndata : %d | Freq : %d",root->data,root->freq);
Traverse(root->right);

}

int NodeCount(TNode* root){

if(!root){
return 0;
}

return NodeCount(root->left)+1+NodeCount(root->right);

}


void FillDataFreq(TNode* root,dFreq arr[],int* index){

if(!root){
return;
}

FillDataFreq(root->left,arr,index);
arr[(*index)].data=root->data;
arr[(*index)].count=root->freq;
(*index)++;
FillDataFreq(root->right,arr,index);


}


void Swap(dFreq arr[],int left ,int right){

int tmpData=arr[left].data;
int tmpFreq=arr[left].count;

arr[left].data=arr[right].data;
arr[left].count=arr[right].count;

arr[right].data=tmpData;
arr[right].count=tmpFreq;

}

int Partition(dFreq arr[],int low,int high){

int pivotData=arr[low].data;
int pivotFreq=arr[low].count;

int left=low;
int right=high;

while(left<right){

while(arr[left].count<=pivotFreq){
left++;
}

while(arr[right].count>pivotFreq){
right--;
}

if(left<right){
Swap(arr,left,right);
}

}

//Maintains original order if two numbers have same count
if(arr[low].count==arr[right].count){
return right;
}


arr[low].data=arr[right].data;
arr[low].count=arr[right].count;

arr[right].data=pivotData;
arr[right].count=pivotFreq;

return right;

}


void QuickSort(dFreq arr[],int low,int high){

if(low<high){

int pivot=Partition(arr,low,high);
QuickSort(arr,low,pivot-1);
QuickSort(arr,pivot+1,high);



}



}


void SortByFrequency(int* arr,int n){

TNode* root=NULL;

int i;

for(i=0;i<n;i++){
root=Insert(root,arr[i]);
}

//Traverse(root);
int nodeCount=NodeCount(root);
//printf("\nNode count : %d",nodeCount);
dFreq tArr[nodeCount+1];
int index=0;
FillDataFreq(root,tArr,&index);

/*
for(i=0;i<index;i++){
printf("\n%d  %d",tArr[i].data,tArr[i].count);
}
getch();
*/
QuickSort(tArr,0,index-1);
/*
for(i=index-1;i>=0;i--){
printf("\n%d  %d",tArr[i].data,tArr[i].count);
}
*/

int j;

for(i=index-1,j=0;i>=0;i--){
while(tArr[i].count--){
arr[j++]=tArr[i].data;
}
}

}


int main(){


int arr[]={2,3,2,4,5,12,2,3,3,3,12};

int n=sizeof(arr)/sizeof(arr[0]);

SortByFrequency(arr,n);

printf("\nSorted a/c to freq\n");

int i;

for(i=0;i<n;i++){
printf("%d   ",arr[i]);
}








return 0;
}
