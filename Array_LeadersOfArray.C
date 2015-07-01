#include<stdio.h>
#include<conio.h>


void FindLeaders(int* arr,int n){
printf("%d  ",arr[n-1]);
int i;
int max=arr[n-1];

for(i=n-2;i>=0;i--){

if(arr[i]>max){
max=arr[i];
printf("%d  ",max);
}
}

}

int main(){

int arr[]={16,17,4,3,5,2};

int n=sizeof(arr)/sizeof(arr[0]);

int i;

FindLeaders(arr,n);

getch();

return 0;
}
