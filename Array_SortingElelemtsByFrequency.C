#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct BinaryNode{
int index;
int count;
int elm;
struct BinaryNode* left,*right;
};
typedef struct BinaryNode BNode;

struct AaNode{
int index;
int count;
};
typedef struct AaNode ANode;


BNode* NewNode(int data,int index){
BNode* tmpNode=(BNode*)malloc(sizeof(BNode));
tmpNode->index=index;
tmpNode->elm=data;
tmpNode->count=1;
tmpNode->left=NULL;
tmpNode->right=NULL;
return tmpNode;
}

BNode* Insert(BNode* root,int index,int data){
if(!root){
return NewNode(data,index);
}

if(root->elm==data){
root->count++;
}

if(root->elm>data){
root->left=Insert(root->left,index,data);
}else{
root->right=Insert(root->right,index,data);
}

return root;

}

void Traverse(BNode* root,ANode buffer[],int* index){

if(!root){
return;
}

Traverse(root->left,buffer,index);
buffer[(*index)].index=root->index;
buffer[(*index)].count=root->count;
(*index)++;
Traverse(root->right,buffer,index);
}

int cmp(const void* a,const void* b){
return *((ANode) a).count-*((ANode )b).count;
}

int main(){
int n;
printf("\nENter the number of elements : ");
scanf("%d",&n);
BNode* root=NULL;
int i;
int data;
int index;
int* arr=(int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++){
printf("\nEnter data : ");
scanf("%d",&data);
arr[i]=data;
root=Insert(root,i,data);
}

ANode buffer[n];
index=0;
Traverse(root,buffer,&index);

for(i=0;i<index;i++){
printf("\n%d  %d",buffer[i].index,buffer[i].count);
}

qsort(buffer,n,sizeof(ANode),cmp);



return 0;
}
