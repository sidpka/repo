#include<stdio.h>
#include<conio.h>


int max(int a,int b){
return a>b?a:b;
}

int GetLargestSum(int* arr,int n){

int Sum[n];


int i;

Sum[0]=arr[0];

Sum[1]=arr[1]>arr[0]?arr[1]:arr[0];
Sum[2]=max(arr[2]+Sum[0],arr[2]+Sum[1],Sum[2]);

for(i=3;i<n;i++){
Sum[i]=max(max(Sum[i-3]+arr[i-1]+arr[i],Sum[i-2]+arr[i]),Sum[i-1]);
}

return Sum[n-1];

}

int main(){

int arr[]={-2,11,-4,13,-5,2};

int largestSum=GetLargestSum(arr,sizeof(arr)/sizeof(arr[0]));

printf("\nContinuous Largest Sum : %d",largestSum);






return 0;
}
