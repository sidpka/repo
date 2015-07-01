#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

void FindPair(int* arr,int n,int X){


int i=0;
int j=n-1;

int minDiff=INT_MAX;
int a,b;

while(i<j){
if(abs(arr[i]+arr[j]-X)<minDiff){
    a=arr[i];
b=arr[j];
minDiff=abs(arr[i]+arr[j]-X);

}

if(arr[i]+arr[j]<X){
i++;
}else{
j--;
}

}


printf("\nPair with sum Closest to : %d are [%d,%d]",X,a,b);


}

int main(){

int arr[]={10,22,28,29,30,40};
int n=sizeof(arr)/sizeof(arr[0]);
int X=54;
FindPair(arr,n,X);



return 0;
}
