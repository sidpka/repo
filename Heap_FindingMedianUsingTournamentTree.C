#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

struct HeapNode{

int* Array;
int count;
int index;

};

typedef struct HeapNode HNode;

HNode* NewNode(int count){

HNode* newNode=(HNode*)malloc(sizeof(HNode));
newNode->index=0;
newNode->count=count;
newNode->Array=(int*)malloc(sizeof(int)*newNode->count);
return newNode;
}

HNode* MaxNode(){

HNode* tmpNode=NewNode(1);
tmpNode->Array[0]=INT_MAX;
return tmpNode;
}

int LeftChild(int i){
return 2*i+1;
}

int RightChild(int i){
return 2*i+2;
}

int RunETL(HNode** heapArray,int n){

int i;
int height=ceil(log2(n));



for(i=(int)pow(2,height)-2;i>=0;i--){

//printf("\nEntering here\n");


if(heapArray[LeftChild(i)]->index==heapArray[LeftChild(i)]->count){
heapArray[i]=heapArray[RightChild(i)];
}
else if(heapArray[RightChild(i)]->index==heapArray[RightChild(i)]->count){
heapArray[i]=heapArray[LeftChild(i)];
}
else if(heapArray[LeftChild(i)]->index<heapArray[LeftChild(i)]->count  && heapArray[RightChild(i)]->index<heapArray[RightChild(i)]->count){
/*
int left=LeftChild(i);
int right=RightChild(i);
printf("\n%d %d",left,right);
printf("\n\n Data fetching :  left child %d",heapArray[left]->Array[heapArray[right]->index]);
printf("\n\n Data fetching :  right child %d",heapArray[right]->Array[heapArray[right]->index]);
*/
if(heapArray[LeftChild(i)]->Array[heapArray[LeftChild(i)]->index] < heapArray[RightChild(i)]->Array[heapArray[RightChild(i)]->index]){
heapArray[i]=heapArray[LeftChild(i)];
}else{
heapArray[i]=heapArray[RightChild(i)];
}
}else{
heapArray[i]=MaxNode();
}
}
int result=heapArray[0]->Array[heapArray[0]->index];
heapArray[0]->index++;
return result;

}


int main(){

int n;

printf("\nEnter the number of teams participating : \n");
scanf("%d",&n);
int height=ceil(log2(n));
//printf("\nHeight is : %d",height);
HNode** heapArray=(HNode**)malloc(sizeof(HNode*)*2*(int)pow(2,height));

int i;
int count;
int j=0;
int k;
for(i=(int)pow(2,height)-1;i<2*(int)pow(2,height)-1;i++){
printf("\nHere we create %d sorted array to participat in tournament \n",j);
printf("\nEnter the number of memebers in this team : ");
scanf("%d",&count);
if(j==n){
heapArray[i]=NewNode(1);
heapArray[i]->Array[0]=INT_MAX;
}else{

heapArray[i]=NewNode(count);
//printf("\n\nIndex of new allocated node : %d",heapArray[i]->index);
printf("\nEnter elements of this array :\n");
for(k=0;k<heapArray[i]->count;k++){
scanf("%d",&heapArray[i]->Array[k]);
}
}
j++;
//printf("\n\nData entered \n\n");
//getch();

}

for(i=0;i<(int)pow(2,height)-1;i++){
heapArray[i]=(HNode*)malloc(sizeof(HNode));
}
/*
printf("\n\nGetting data  \n\n");
getch();
for(i=pow(2,height)-1;i<2*n-1;i++){
printf("\nelements of this array :\n");
for(k=0;k<heapArray[i]->count;k++){
printf("%d  ",heapArray[i]->Array[k]);
}
getch();
}
*/

/*
printf("\nEnter which samllest u want to see : ");
scanf("%d",&j);
*/
j=0;
i=(int)pow(2,height)-1;
for(k=0;k<n;k++){
j+=heapArray[i++]->count;
}

int result1=0;

int result;
result=0;
for(i=0;i<=j/2;i++){
    //does not work is smallest element is less than 0;
    if(result){
    result1=result;
    }
result=RunETL(heapArray,n);
/*
for(k=(int)pow(2,height)-2;k>=0;k--){
printf("\n K is : %d",k);
getch();
int left=LeftChild(k);
int right=RightChild(k);
printf("\n\n Data fetching :  left child %d",heapArray[left]->Array[heapArray[right]->index]);
printf("\n\n Data fetching :  right child %d",heapArray[right]->Array[heapArray[right]->index]);
getch();
if(heapArray[LeftChild(k)]->Array[heapArray[LeftChild(k)]->index]< heapArray[RightChild(k)]->Array[heapArray[RightChild(k)]->index]){
heapArray[k]=heapArray[LeftChild(k)];
}else{
heapArray[k]=heapArray[RightChild(k)];
}
}

result=heapArray[0]->Array[heapArray[0]->index];
heapArray[0]->index++;
*/
//printf("\n\n%dth samllest element is : %d",i,result);
//getch();
}

if(j%2==0){
result=(result+result1)/2;
}

printf("\n\nMedian is : %d",result);
getch();

return 0;

}
