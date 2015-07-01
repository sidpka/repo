#include<stdio.h>
#include<conio.h>

void Reverse(int* arr,int low,int high){

int i=low;
int k=high;
int tmp;
while(i<k){
tmp=arr[i];
arr[i]=arr[k];
arr[k]=tmp;
i++;
k--;
}

}

void Rotate(int* arr,int n,int d){
Reverse(arr,0,d-1);
Reverse(arr,d,n-1);
Reverse(arr,0,n-1);
}

void Rotate2(int* arr,int n,int d){
Reverse(arr,n-d,n-1);
Reverse(arr,0,n-d-1);
Reverse(arr,0,n-1);

}

int main(){

int arr[]={1,2,3,4,5,6,7};
int n=sizeof(arr)/sizeof(arr[0]);

int d;
printf("\nEnter the value of d : ");
scanf("%d",&d);

printf("\nBefore \n\n");
int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}
/*
Rotate(arr,n,d);
*/
//Rotate left

//RotateRight

Rotate2(arr,n,d);

printf("\nAfter\n\n");

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}











return 0;
}
