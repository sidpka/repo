#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct Jobs{
int start;
int finish;
int profit;
};

typedef struct Jobs Job;

struct Stack{
Job** SArray;
int top;
int capacity;
};
typedef struct Stack SNode;


SNode* CreateStack(int n){
SNode* tmpNode=(SNode*)malloc(sizeof(SNode));
tmpNode->top=-1;
tmpNode->capacity=n;

tmpNode->SArray=(Job**)malloc(sizeof(Job*)*n);

int i;

for(i=0;i<n;i++){
tmpNode->SArray[i]=(Job*)malloc(sizeof(Job));
}

return tmpNode;
}

int IsStackEmpty(SNode* node){
return node->top==-1;
}

void Push(SNode* node,Job j){

++node->top;
node->SArray[node->top]->start=j.start;
node->SArray[node->top]->finish=j.finish;
node->SArray[node->top]->profit=j.profit;

}

void Pop(SNode* node){
node->top--;
}


void Swap(Job arr[],int left,int right){

int tmpStart=arr[left].start;
int tmpFinish=arr[left].finish;
int tmpProfit=arr[left].profit;

arr[left].start=arr[right].start;
arr[left].finish=arr[right].finish;
arr[left].profit=arr[right].profit;

arr[right].start=tmpStart;
arr[right].finish=tmpFinish;
arr[right].profit=tmpProfit;





}

int Partition(Job arr[],int low,int high){

int left=low;
int right=high;

int pivotStart=arr[low].start;
int pivotFinish=arr[low].finish;
int pivotProfit=arr[low].profit;


while(left<right){

while(arr[left].finish<=pivotFinish){
left++;
}

while(arr[right].finish>pivotFinish){
right--;
}

if(left<right){
Swap(arr,left,right);
}

}

if(arr[low].finish==arr[right].finish && arr[low].start<=arr[right].start){
return right;
}

arr[low].start=arr[right].start;
arr[low].finish=arr[right].finish;
arr[low].profit=arr[right].finish;

arr[right].start=pivotStart;
arr[right].finish=pivotFinish;
arr[right].profit=pivotProfit;

return right;





}

void QuickSort(Job arr[],int low,int high){

if(low<high){
int pivot=Partition(arr,low,high);
QuickSort(arr,low,pivot-1);
QuickSort(arr,pivot+1,high);
}


}

int FindMaxProfit(Job arr[],int n){

QuickSort(arr,0,n-1);

SNode* stack=CreateStack(n);

Push(stack,arr[0]);

int i;

for(i=1;i<n;i++){
while(stack->SArray[stack->top]->finish> arr[i].start && stack->SArray[stack->top]->profit< arr[i].profit  && !IsStackEmpty(stack)){
Pop(stack);
}

if(stack->SArray[stack->top]->finish<= arr[i].start){
Push(stack,arr[i]);
}


}

//printf("\n%d",stack->SArray[stack->top]->profit);

int maxProfit=0;

while(!IsStackEmpty(stack)){
maxProfit+=stack->SArray[stack->top]->profit;
//printf("\nMax Prifr; %d",maxProfit);
Pop(stack);
}

return maxProfit;
}

int main(){

Job arr[]={{1,2,50},{3,5,20},{6,19,100},{2,100,200}};

printf("\nMax Profit : %d",FindMaxProfit(arr,sizeof(arr)/sizeof(arr[0])));







return 0;
}
