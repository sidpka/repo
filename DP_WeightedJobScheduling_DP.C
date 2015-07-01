#include<stdio.h>
#include<conio.h>


struct Jobs{
int start;
int finish;
int profit;
};
typedef struct Jobs Job;

void Swap(Job arr[],int left,int right){

int start=arr[left].start;
int end=arr[left].finish;
int profit=arr[left].profit;

arr[left].start=arr[right].start;
arr[left].finish=arr[right].finish;
arr[left].profit=arr[right].profit;

arr[right].start=start;
arr[right].finish=end;
arr[right].profit=profit;




}

int Partition(Job arr[],int low,int high){

int pivotStart=arr[low].start;
int pivotEnd=arr[low].finish;
int pivotProfit=arr[low].profit;

int left=low;
int right=high;

while(left<right){


while(arr[left].finish<=pivotEnd){
left++;
}

while(arr[right].finish>pivotEnd){
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
arr[low].profit=arr[right].profit;

arr[right].start=pivotStart;
arr[right].finish=pivotEnd;
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


int max(int a,int b){
return a>b?a:b;
}

int GetNonOverlapping(Job arr[],int i){

int j;

for(j=i-1;j>=0;j--){

if(arr[j].finish<=arr[i].start){
return j;
}
}
return -1;


}

int GetMaxProfit_Util(Job arr[],int n){

int tmp[n];

tmp[0]=arr[0].profit;


int i;

for(i=1;i<n;i++){

int incProfit=arr[i].profit;
int l=GetNonOverlapping(arr,i);
if(l!=-1){
incProfit+=tmp[l];
}
int excProfit=tmp[i-1];
tmp[i]=max(incProfit,excProfit);

}
return tmp[n-1];


}


int GetMaxProfit(Job arr[],int n){

QuickSort(arr,0,n-1);

int i;

/*
for(i=0;i<n;i++){
printf("\n%d  %d  %d",arr[i].start,arr[i].finish,arr[i].profit);
}

getch();
*/

return GetMaxProfit_Util(arr,n);



}


int main(){

Job arr[]={{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
int n=sizeof(arr)/sizeof(arr[0]);

printf("\nMax Profit obtained : %d",GetMaxProfit(arr,n));


return 0;
}
