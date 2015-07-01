#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct IntervalNode{
int low;
int high;
};
typedef struct IntervalNode Interval;

struct IntervalTree{
int max;
Interval* inv;
struct IntervalTree* left;
struct IntervalTree* right;
};
typedef struct IntervalTree INode;


INode* NewNode(Interval* tmpNode){

INode* newNode=(INode*)malloc(sizeof(INode));
newNode->max=tmpNode->high;
newNode->left=NULL;
newNode->right=NULL;
newNode->inv=(Interval*)malloc(sizeof(Interval));
newNode->inv->low=tmpNode->low;
newNode->inv->high=tmpNode->high;
return newNode;
}


INode* InsertInterval(INode* root,Interval* tmpNode){

if(!root){
return NewNode(tmpNode);
}

if(root->inv->low > tmpNode->low){
root->left=InsertInterval(root->left,tmpNode);
}else{
root->right=InsertInterval(root->right,tmpNode);
}

if(root->max< tmpNode->high){
root->max=tmpNode->high;
}

return root;
}

void Traversal(INode* root){
    if(!root){
    return;
    }

    Traversal(root->left);
    printf("\n[%d--%d]  : Max: %d",root->inv->low,root->inv->high,root->max);
    Traversal(root->right);


}

int SearchInterval_Util(INode* root,Interval* tmpNode){

if(root->inv->low<=tmpNode->high && tmpNode->low<=root->inv->high){
return 1;
}else{
return 0;
}

}


Interval* SearchInterval(INode* root,Interval* tmpNode){
if(!root){
return NULL;
}

if(SearchInterval_Util(root,tmpNode)){
return root->inv;
}

if(root->left && root->left->max>=tmpNode->low){
return SearchInterval(root->left,tmpNode);
}else{
return SearchInterval(root->right,tmpNode);
}
}

int main(){
int n,i;
printf("\nEnter the number of nodes : ");
scanf("%d",&n);
Interval* tmpNode=(Interval*)malloc(sizeof(Interval));
INode* root=NULL;
int lowVal,highVal;
for(i=0;i<n;i++){
printf("\nEnter low and high value of interval for node :  ");
scanf("%d %d",&lowVal,&highVal);
tmpNode->low=lowVal;
tmpNode->high=highVal;
root=InsertInterval(root,tmpNode);
}
printf("\nPress enter to traverse \n");
getch();
Traversal(root);
getch();
printf("\nEnter an interval to see if it overlaps with any interval in the tree :\n");
scanf("%d %d",&lowVal,&highVal);
tmpNode->low=lowVal;
tmpNode->high=highVal;

tmpNode=SearchInterval(root,tmpNode);
if(!tmpNode){
printf("\nNo overlapping interval in tree");
}else{
printf("\nOverlapping interval  : \n");
printf("[%d--%d]",tmpNode->low,tmpNode->high);
}
getch();


return 0;
}
