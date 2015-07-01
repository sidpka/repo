#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>


struct PointNode{
int x;
int y;
int isRight;
int lineIndex;
};
typedef struct PointNode Points;

struct LineNode{
Points p;
Points q;
};
typedef struct LineNode Lines;

struct BSTNode{
Points data;
struct BSTNode* left;
struct BSTNode* right;
};
typedef struct BSTNode TNode;



TNode* NewNode(Points data){
TNode* tmpNode=(TNode*)malloc(sizeof(TNode));
tmpNode->data=data;
tmpNode->left=NULL;
tmpNode->right=NULL;
return tmpNode;
}

TNode* Insert(TNode* root,Points data){

if(!root){
return NewNode(data);
}

if(root->data.y<data.y){
root->right=Insert(root->right,data);
}else{

root->left=Insert(root->left,data);
}

return root;
}

Points GetMax(TNode* root){
if(!root){
return (Points){-1,-1,-1,-1};
}
while(root->right){
root=root->right;
}
return root->data;
}

TNode* Remove(TNode* root,Points data){
if(!root){
return root;
}


if(root->data.y==data.y){

if(root->left==NULL && root->right==NULL){
return NULL;
}else if(root->left && root->right){
Points tmp=GetMax(root->left);
root->data=tmp;
root->left=Remove(root->left,tmp);
}else if(root->left){
root=root->left;
}else{
root=root->right;
}

return root;
}


if(root->data.y<data.y){
return Remove(root->right,data);
}
else if(root->data.y>data.y){
return Remove(root->left,data);
}




}


Points GetMin(TNode* root){
    if(!root){
return (Points){-1,-1,-1,-1};
}
while(root->left){
root=root->left;
}

return root->data;
}
Points GetFloor(TNode* root,Points data){

if(!root){
return (Points){-1,-1,-1,-1};
}

if(root->data.y==data.y){
return GetMax(root->left);
}else if(root->data.y<data.y){
return GetFloor(root->right,data);
}else{
return GetFloor(root->left,data);
}


}

Points GetCeil(TNode* root,Points data){

if(!root){
return Points{-1,-1,-1,-1};
}

if(root->data.y==data.y){
return GetMin(root->right);
}else if(root->data.y<data.y){
return GetCeil(root->right,data);
}else{
return GetCeil(root->left,data);
}


}


int max(int a,int b){

return a>b?a:b;
}

int min(int a,int b){

return a<b?a:b;
}

void FindUpdatedPoints(Lines line[],int n){

int i;

for(i=0;i<n;i++){

line[i].p.isRight=(line[i].p.x >line[i].q.x)?1:0;
line[i].q.isRight=1-line[i].p.isRight;
line[i].p.lineIndex=i;
line[i].q.lineIndex=i;
}




}

void Swap(Points* a,Points* b){
Points tmp=*a;
*a=*b;
*b=tmp;

}

int Partition(Points arr[],int low,int high){

int left=low;
int right=high;

int pivotElm=arr[low].x;

while(left<right){

while(arr[left].x<=pivotElm){
left++;
}

while(arr[right].x>pivotElm){
right--;
}

if(left<right){
Swap(&arr[left],&arr[right]);
}


}

Swap(&arr[low],&arr[right]);

return right;


}

void QuickSort(Points arr[],int low,int high){

if(low<high){
int pivot=Partition(arr,low,high);
QuickSort(arr,low,pivot-1);
QuickSort(arr,pivot+1,high);
}



}

int FindOrient(Points p,Points q,Points r){

int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);

if(val==0){
return 0;
}

return  (val>0)?1:2;

}


int FindOnLine(Points p,Points q,Points r){

if( (q.x<=max(p.x,r.x)  && q.x>=min(p.x,r.x)) && (q.y<=max(p.y,r.y) && q.y>=min(p.y,r.y))   ){

return 1;
}

return 0;
}

int FindIfInterests(Lines line1,Lines line2){

int o1=FindOrient(line1.p,line1.q,line2.p);
int o2=FindOrient(line1.p,line1.q,line2.q);
int o3=FindOrient(line2.p,line2.q,line1.p);
int o4=FindOrient(line2.p,line2.q,line1.q);

if(o1!=o2 && o3!=o4){
return 1;
}

if(o1==0 && FindOnLine(line1.p,line2.p,line1.q)){
return 1;
}

if(o2==0 && FindOnLine(line1.p,line2.q,line1.q)){
return 1;
}

if(o3==0 && FindOnLine(line2.p,line1.p,line2.q)){
return 1;
}

if(o4==0 && FindOnLine(line2.p,line1.q,line2.q)){
return 1;
}

return 0;

}


void Traverse(TNode* root){
if(!root){
return;
}

Traverse(root->left);
printf("\nx:%d  y:%d\n",root->data.x,root->data.y);
Traverse(root->right);

}

int FindNumberOfIntersections(Lines line[],int n){

FindUpdatedPoints(line,n);

//printf("\nisRight : %d",line[0].q.isRight);

Points point[2*n];

int i;
int index=0;
for(i=0;i<n;i++){
point[index++]=line[i].p;
point[index++]=line[i].q;
}

/*
for(i=0;i<2*n;i++){
printf("\nx: %d  y: %d   isRight: %d  lineIndex: %d",point[i].x,point[i].y,point[i].isRight,point[i].lineIndex);
}
*/

QuickSort(point,0,2*n-1);

/*
printf("\n\n");
for(i=0;i<2*n;i++){
printf("\nx: %d  y: %d   isRight: %d  lineIndex: %d",point[i].x,point[i].y,point[i].isRight,point[i].lineIndex);
}
*/

int count=0;

TNode* root=NULL;

/*
root=Insert(root,point[0]);
root=Insert(root,point[1]);
root=Insert(root,point[2]);

Traverse(root);
Points tmp=GetCeil(root,point[0]);
printf("Ceil of : %d is : %d",point[0].y,tmp.lineIndex);
*/

for(i=0;i<2*n;i++){
Points tmp1=GetCeil(root,point[i]);
Points tmp2=GetFloor(root,point[i]);

if(point[i].isRight){
if(tmp1.lineIndex!=-1 && tmp2.lineIndex!=-1){
if(FindIfInterests(line[tmp1.lineIndex],line[tmp2.lineIndex])){
count++;
}
}
tmp1=line[point[i].lineIndex].p.isRight==0?line[point[i].lineIndex].p:line[point[i].lineIndex].q;
root=Remove(root,tmp1);
}else{
root=Insert(root,point[i]);
if(tmp1.lineIndex!=-1){
if(FindIfInterests(line[point[i].lineIndex],line[tmp1.lineIndex])){
count++;
}

}

if(tmp2.lineIndex!=-1){
if(FindIfInterests(line[point[i].lineIndex],line[tmp2.lineIndex])){
count++;
}

}

}


}

//printf("\nCount : %d",count);

return count;
}

int main(){

//Points p[]={{2,3},{4,5} };

Lines ln[]={ {{8,0},{12,0} } ,{{3,1},{15,4} },{{7,10},{10,10} },{{0,3},{4,3} },{{2,7},{14,2} }  };
int n=sizeof(ln)/sizeof(ln[0]);

//printf("\n%d  %d  %d",p[1].x,p[1].y,p[1].isRight);

//printf("\nLine : %d , Leftx : %d,Right y : %d\n Is right : %d",0,ln[0].p.x,ln[0].q.y,ln[0].q.isRight);
//printf("\n%d",n);
int count =FindNumberOfIntersections(ln,n);
printf("\n%d intersection point",count);

return 0;
}
