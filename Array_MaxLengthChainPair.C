#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Pair{
int a;
int b;
};

typedef struct Pair pairs;


int MaxChainLen(pairs* arr,int n){

int* mcl=(int*)malloc(sizeof(int)*n);

int i;

for(i=0;i<n;i++){
mcl[i]=1;
}

int j;
int max=0;

for(i=1;i<n;i++){
for(j=0;j<i;j++){

if(arr[i].a > arr[j].b && mcl[i]<mcl[j]+1){
mcl[i]=mcl[j]+1;
}

}
}

for(i=0;i<n;i++){
if(mcl[i]>max){
max=mcl[i];
}
}


return max;


}


int Partition(pairs* arr,int low,int high){

int pivotElm=arr[low].a;
int pivotBase=arr[low].b;

int left=low;
int right=high;
int a,b;
while(left<right){

while(arr[left].a<=pivotElm){

left++;

}

while(arr[right].a>pivotElm){
right--;
}

if(left<right){
a=arr[left].a;
b=arr[left].b;
arr[left].a=arr[right].a;
arr[left].b=arr[right].b;
arr[right].a=a;
arr[right].b=b;
}


}

arr[low].a=arr[right].a;
arr[low].b=arr[right].b;

arr[right].a=pivotElm;
arr[right].b=pivotBase;

return right;


}

void QuickSort(pairs* arr,int low,int high){

if(high>low){

int pivot=Partition(arr,low,high);

QuickSort(arr,low,pivot-1);
QuickSort(arr,pivot+1,high);



}


}


int main(){

pairs arr[]={{5,24},{39,60},{15,28},{27,40},{50,90}};

int n=sizeof(arr)/sizeof(arr[0]);


printf("\nBefore sorting\n");

int i;

for(i=0;i<n;i++){

printf("\n%d  %d",arr[i].a,arr[i].b);
}



QuickSort(arr,0,n-1);
getch();
printf("After Sorting\n");
for(i=0;i<n;i++){
printf("\n%d %d",arr[i].a,arr[i].b);
}
printf("\nMax length : %d",MaxChainLen(arr,n));
return 0;
}
