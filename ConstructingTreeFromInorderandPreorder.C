#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Tree{
int data;
struct Tree* left;
struct Tree* right;
};
typedef struct Tree TNode;

int FindIndex(int* Inorder,int start,int end,int data){
int i;
for(i=start;i<=end;i++){
if(Inorder[i]==data){
break;
}
}
return i;
}

int max(int a,int b){
return a>b?a:b;
}

TNode* CreateTree(int* InOrder,int *PreOrder,int inStart,int inEnd){
static int preIndex=0;
if(inStart>inEnd){
return NULL;
}else{

TNode* newNode=(TNode*)malloc(sizeof(TNode));
int tmpIndex=FindIndex(InOrder,inStart,inEnd,PreOrder[preIndex++]);
newNode->data=InOrder[tmpIndex];
newNode->left=CreateTree(InOrder,PreOrder,inStart,tmpIndex-1);
newNode->right=CreateTree(InOrder,PreOrder,tmpIndex+1,inEnd);
return newNode;
}
}

void Traverse(TNode* root){
if(!root){
return ;
}
Traverse(root->left);
printf("%d  ",root->data);
Traverse(root->right);
}

int main(){
int n;
printf("\nEnter the number of nodes in tree : ");
scanf("%d",&n);
int* InOrder=(int*)malloc(sizeof(int)*n);
int* PreOrder=(int*)malloc(sizeof(int)*n);

printf("\nEnter the InOrder Traversal data : \n");
int i;
for(i=0;i<n;i++){
scanf("%d",&InOrder[i]);
}
printf("\nInorder data taken...");
getch();
printf("\nEnter the PreOrder Traversal data : \n");
for(i=0;i<n;i++){
scanf("%d",&PreOrder[i]);
}
printf("\nInorder data taken...");
getch();
printf("\nPress enter to create tree : \\n");
getch();
TNode* root;
root=CreateTree(InOrder,PreOrder,0,n-1);
printf("\nTree created...");
getch();
printf("\nPress enter to traverse inorder...\n\n");
getch();
Traverse(root);
getch();
return 0;
}
