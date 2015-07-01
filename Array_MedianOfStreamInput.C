#include<stdio.h>
#include<conio.h>

int FindMedian(int* arr,int n){

int i;
/*
int tmp;
for(i=0;i<n;i++){
if(arr[i]>arr[n-1]){
tmp=arr[i];
arr[i]=arr[n-1];
arr[n-1]=tmp;
}
}
*/

//Insertion Sort

int v=arr[n-1];
//i=n-1;
int j=n-1;

while(arr[j-1]>v && j>0){
arr[j]=arr[j-1];
j--;
}
arr[j]=v;

if(n%2){
return arr[n/2];
}else{
    /*
    for(i=0;i<n;i++){
    printf("%d  ",arr[i]);
    }
    */
return (arr[n/2]+arr[n/2-1])/2;
}

}

int main(){

int n;
printf("\nEnter the number of inputs : ");
scanf("%d",&n);
int arr[n];
int i;

int median;
for(i=0;i<n;i++){
printf("\nEnter data : ");
scanf("%d",&arr[i]);
median=FindMedian(arr,i+1);
printf("\nMedian is : %d",median);
}








return 0;
}
