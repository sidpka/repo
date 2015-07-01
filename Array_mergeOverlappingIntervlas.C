#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Intervals{

int start;
int end;

};

typedef struct Intervals interval;

void Swap(interval arr[],int left,int right){

int tmpStart;
int tmpEnd;

tmpStart=arr[left].start;
tmpEnd=arr[left].end;
arr[left].start=arr[right].start;
arr[left].end=arr[right].end;
arr[right].start=tmpStart;
arr[right].end=tmpEnd;


}

int Partition(interval arr[],int low,int high){

int pivotStart=arr[low].start;
int pivotEnd=arr[low].end;

int left=low;
int right=high;

int tmpStart;
int tmpEnd;

while(left<right){

while(arr[left].start<=pivotStart){

left++;


}

while(arr[right].start > pivotStart){
right--;
}

if(left<right){
    //printf("\nArr left start : %d",arr[left].start);
Swap(arr,left,right);
 //printf("\nArr left start : %d",arr[left].start);
}

}

if(arr[right].start==arr[low].start && arr[right].end>=arr[low].end){
return right;
}

arr[low].start=arr[right].start;
arr[low].end=arr[right].end;
arr[right].start=pivotStart;
arr[right].end=pivotEnd;

return right;

}


void QuickSort(interval arr[],int low,int high){

if(high>low){

int pivot=Partition(arr,low,high);
/*
int i;
printf("\nPivot : %d and low : %d high : %d",pivot,low,high);
for(i=0;i<n;i++){
printf("\n%d %d",arr[i].start,arr[i].end);
}
*/
QuickSort(arr,low,pivot-1);
QuickSort(arr,pivot+1,high);



}


}

void FindMergedInterval(interval arr[],int n){

QuickSort(arr,0,n-1);

int i;

/*
for(i=0;i<n;i++){
printf("\n%d  %d",arr[i].start,arr[i].end);
}
*/

int startInterval=arr[0].start;
int endInterval=arr[0].end;

for(i=1;i<n;i++){

if(arr[i].start<endInterval){
endInterval=arr[i].end;
//printf("\nEntering here for %d %d",arr[i].start,arr[i].end);

if(i==n-1){
printf("\n%d %d",startInterval,endInterval);
}



}else if(arr[i].start>=endInterval){
printf("\n%d %d",startInterval,endInterval);
//printf("\Breaking here for %d %d",arr[i].start,arr[i].end);
startInterval=arr[i].start;
endInterval=arr[i].end;
}

}


}

int main(){

interval arr[]={{2,5}, {5,7},{2,4},{1,3},{2,3},{6,8}};

int n=sizeof(arr)/sizeof(arr[0]);

//printf("%d",n);

FindMergedInterval(arr,n);



return 0;
}
