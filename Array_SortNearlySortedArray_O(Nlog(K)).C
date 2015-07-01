#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int Left(int size,int i){

int left=2*i+1;
if(left<size){
return left;
}else{
return -1;
}

}


int Right(int size,int i){


int right=2*i+2;
if(right<size){
return right;
}else{
return -1;
}

}

void Heapify(int* heap,int size,int i){

int left=Left(size,i);
int right=Right(size,i);

int min;

if(left!=-1 && heap[left]<heap[i]){
min=left;
}else{
min=i;
}

if(right!=-1 && heap[right]<heap[min]){
min=right;
}

if(min!=i){
int tmp=heap[min];
heap[min]=heap[i];
heap[i]=tmp;
Heapify(heap,size,min);
}


}

int Replace(int* heap,int size,int elm){

int tmp=heap[0];
heap[0]=elm;

if(tmp<elm){
Heapify(heap,size,0);
}

return tmp;
}

int ExtractMin(int* heap,int size){
int tmp=heap[0];
if(size>1){
heap[0]=heap[size-1];
Heapify(heap,size,0);
}

return tmp;

}




void CreateMinHeap(int* heap,int size){
int i=(size-1)/2;
while(i>=0){
Heapify(heap,size,i);
i--;
}
}

void SortK(int* arr,int n,int K){

int* heap=(int*)malloc(sizeof(int)*K+1);

int i;

for(i=0;i<=K;i++){
heap[i]=arr[i];
}

CreateMinHeap(heap,K+1);

int j;

for(i=K+1,j=0;j<n;i++,j++){

if(i<n){
arr[j]=Replace(heap,K+1,arr[i]);
}else{
arr[j]=ExtractMin(heap,n-j);
}

}


}

int main(){

int arr[]={3,2,1,6,5,4};

int n=sizeof(arr)/sizeof(arr[0]);
int K=4;
SortK(arr,n,K);

printf("\nSorted array :\n");
int i;
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}


return 0;
}
