#include<stdio.h>
#include<conio.h>

int max(int a,int b){
return a>b?a:b;
}


int Kadane(int* arr,int n){

int maxHere=0;
int maxEnd=0;

int i;
for(i=0;i<n;i++){
maxHere+=arr[i];
if(maxHere<0){
maxHere=0;
}else{

   if(maxEnd<maxHere){
   maxEnd=maxHere;
   }
}


}

//printf("\nMax end : %d",maxEnd);
return maxEnd;

}


int FindMaxSum(int* arr,int n){


int maxKadane=Kadane(arr,n);

int wrap=0;

int i;

for(i=0;i<n;i++){
wrap+=arr[i];
arr[i]=-arr[i];
}

wrap=wrap+Kadane(arr,n);

return max(wrap,maxKadane);


}


int main(){


int arr[]={8,-8,9,-9,10,-11,12};

//int arr[]={10,-3,-4,7,6,5,-4,-1};

int n=sizeof(arr)/sizeof(arr[0]);

int result=FindMaxSum(arr,n);

printf("\nMax sum is : %d",result);





return 0;
}


