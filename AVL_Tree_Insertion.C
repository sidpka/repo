#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct AVLNode{
int data;
struct AVLNode* left;
struct AVLNode* right;
int Bf;
};

typedef struct AVLNode ANode;

ANode* NewNode(int data){
ANode* newNode=(ANode*)malloc(sizeof(ANode));
newNode->Bf=0;
newNode->data=data;
newNode->left=NULL;
newNode->right=NULL;
return newNode;
}

void Insert(ANode** root,int data){
if(!(*root)){
(*root)=NewNode(data);
return;
}
if((*root)->data > data){
Insert(&(*root)->left,data);
}else{
Insert(&(*root)->right,data);
}

}


void Traverse(ANode* root){
if(!root){
return;
}

Traverse(root->left);
printf("%d  ->  ",root->data);
Traverse(root->right);
}


int main(){
ANode* root=NULL;
printf("\nEnter the number of nodes you want to enter : ");
int n;
scanf("%d",&n);

int i;
int data;
for(i=0;i<n;i++){
printf("\nEnter the value of node you want to enter : ");
scanf("%d",&data);
Insert(&root,data);
}
printf("\n%d nodes added \n\n");
getch();
printf("\nPress enter to traverse\n");
Traverse(root);




return 0;
}
