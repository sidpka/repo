#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Point{
int D;
int* cord;
};
typedef struct Point PNode;

struct Bunch{
int count;
PNode** BArray;
};
typedef struct Bunch BNode;

struct KDTree{
PNode* pnt;
struct KDTree* left,*right;
};
typedef struct KDTree KDNode;

KDNode* NewNode(PNode* pnt){

    KDNode* tmpNode=(KDNode*)malloc(sizeof(KDNode));
    tmpNode->left=NULL;
    tmpNode->right=NULL;
    tmpNode->pnt=pnt;

return tmpNode;
}

PNode* CreatePoint(int dimensions){
    PNode* tmpNode=(PNode*)malloc(sizeof(PNode));
    tmpNode->D=dimensions;
    tmpNode->cord=(int*)malloc(sizeof(int)*dimensions);
return tmpNode;
}

BNode* CreateBunch(int n){

BNode* tmpNode=(BNode*)malloc(sizeof(BNode));
tmpNode->count=n;
tmpNode->BArray=(PNode**)malloc(sizeof(PNode*)*n);
int i;
for(i=0;i<n;i++){
tmpNode->BArray[i]=NULL;
}

return tmpNode;
}


KDNode* InsertKD(KDNode* root,PNode* pnt,int depth){

if(!root){
return NewNode(pnt);
}

int axisOfComparison=depth%pnt->D;

if(root->pnt->cord[axisOfComparison] > pnt->cord[axisOfComparison]){
root->left=InsertKD(root->left,pnt,depth+1);
}else{
root->right=InsertKD(root->right,pnt,depth+1);
}

return root;

}


void PrintKD(PNode* pnt){
int i;
int size=pnt->D;
printf("\n");
for(i=0;i<size;i++){
printf("%d , ",pnt->cord[i]);
}
}

void TraversalKD(KDNode* root){
if(!root){
return;
}

TraversalKD(root->left);
PrintKD(root->pnt);
TraversalKD(root->right);

}

int IsSamePoint(KDNode* node,PNode* pnt){
if(node->pnt->D!=pnt->D){
return 0;
}

int i;

for(i=0;i<pnt->D;i++){
if(node->pnt->cord[i]!=pnt->cord[i]){
return 0;
}
}
return 1;
}

int SearchKD(KDNode* root,PNode* pnt,int depth){


if(!root){
return 0;
}

if(IsSamePoint(root,pnt)){
return 1;
}


int axisOfComparison=depth%pnt->D;

if(root->pnt->cord[axisOfComparison]>pnt->cord[axisOfComparison]){
return SearchKD(root->left,pnt,depth+1);
}else{
return SearchKD(root->right,pnt,depth+1);
}



}

int main(){

int pointCount;
int dimensions;

printf("\nEnter the number of points : ");
scanf("%d",&pointCount);
printf("\nEnter the dimesnions : ");
scanf("%d",&dimensions);

KDNode* root=NULL;

printf("\nInsert points in tree : ");
int i;
int j;

for(i=0;i<pointCount;i++){
printf("\nEnter coordinates : \n");
PNode* tmpPoint=CreatePoint(dimensions);
for(j=0;j<dimensions;j++){
scanf("%d",&tmpPoint->cord[j]);
}
root=InsertKD(root,tmpPoint,0);
}

printf("\nPress enter to traverse \n");
getch();

TraversalKD(root);
getch();

printf("\nEnter a point to search if it exists : ");
printf("\nEnter coordinates : \n");
PNode* tmpPoint=CreatePoint(dimensions);
for(j=0;j<dimensions;j++){
scanf("%d",&tmpPoint->cord[j]);
}

int result= SearchKD(root,tmpPoint,0);

if(result){
printf("\nYes");
}else{
printf("\No");
}

return 0;
}
