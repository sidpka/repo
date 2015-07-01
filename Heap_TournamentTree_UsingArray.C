#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

struct TreeNode{
int data;
struct TreeNode* left,* right;
};
typedef struct TreeNode TNode;

TNode* NewNode(int data){
TNode* newNode=(TNode*)malloc(sizeof(TNode));
newNode->data=data;
newNode->left=NULL;
newNode->right=NULL;
return newNode;
}

int IsLeafNode(TNode* root){
return root->left==NULL && root->right==NULL;
}

int max(int a,int b){
return (a>b)?a:b;
}

TNode* GetTournament(int Array[],int height,int* index,int limitHeight){

if(height>limitHeight){
return NULL;
}

TNode* left=GetTournament(Array,height+1,index,limitHeight);
TNode* right=GetTournament(Array,height+1,index,limitHeight);

TNode* root;

if(height==limitHeight){
root=NewNode(Array[(*index)++]);
}
else{
root=NewNode(max(left->data,right->data));
}

root->left=left;
root->right=right;
return root;
}


void InOrder(TNode* root){
if(!root){
return;
}
InOrder(root->left);
printf("%d  ",root->data);
InOrder(root->right);
}


void GetSecondWinner(TNode* root,int Winner,int* secondWinner){
if(!root->left && !root->right){
return;
}

if(root->right->data==Winner){
if(root->left->data> (*secondWinner)){
(*secondWinner)=root->left->data;
}
GetSecondWinner(root->right,Winner,secondWinner);
}
if(root->left->data==Winner){
if(root->right->data> (*secondWinner)){
(*secondWinner)=root->right->data;
}
GetSecondWinner(root->left,Winner,secondWinner);
}
}

int LeftChild(int i,int n){
int left=2*i+1;
if(left>=2*n-1){
return -1;
}else{
return left;
}
}

int RightChild(int i,int n){
int right=2*i+2;
if(right>=2*n-1){
return -1;
}else{
return right;
}
}

int main(){
int Array[]={1,4,6,8,9,10,11,4};

int n=sizeof(Array)/sizeof(Array[0]);

int index=0;
int height=log2(n);

int* tournamentArray=(int*)malloc(sizeof(int)*2*n);
int start=(int)pow(2,height)-1;
int i;
int j=0;
for(i=start;i<2*n-1;i++){
tournamentArray[i]=Array[j++];
}
/*
for(i=start;i<2*n-1;i++){
printf("%d  ",tournamentArray[i]);
}
*/
for(i=start-1;i>=0;i--){
tournamentArray[i]=max(tournamentArray[2*i+1],tournamentArray[2*i+2]);
}
/*
printf("\n");

for(i=0;i<2*n-1;i++){
printf("%d  ",tournamentArray[i]);
}
*/
printf("\nWinner is : %d\n",tournamentArray[0]);
getch();
printf("\nPress enter to find second winner : \n");
getch();
int runnerUp=-1;
int winner=tournamentArray[0];

int ind=0;


while(ind<(2*n-1)/2){
if(tournamentArray[2*ind+1]==winner){
if(tournamentArray[2*ind+2]>runnerUp){
runnerUp=tournamentArray[2*ind+2];
}
ind=2*ind+1;
}

if(tournamentArray[2*ind+2]==winner){
if(tournamentArray[2*ind+1]>runnerUp){
runnerUp=tournamentArray[2*ind+1];
}
ind=2*ind+2;
}

}


printf("\n\nRunner Up : %d",runnerUp);
return 0;
}
