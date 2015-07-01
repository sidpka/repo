#include<stdio.h>
#include<conio.h>


void RotateArray(int* arr,int n,int d){
if(d==0){
return;
}
int tmp=arr[0];

arr[0]=arr[n-1];
int i;

for(i=n-1;i>1;i--){
arr[i]=arr[i-1];
}
arr[1]=tmp;
RotateArray(arr,n,d-1);
}

void RotateArray1(int* arr,int n,int d){
if(d==0){
return;
}

int tmp[d];
int i;
int j=0;
for(i=n-d;i<n;i++){
tmp[j++]=arr[i];
}

/*
for(i=0;i<d;i++){
printf("%d  ",tmp[i]);
}
*/

for(i=n-1;i>=d;i--){
arr[i]=arr[i-d];
}

for(i=0;i<d;i++){
arr[i]=tmp[i];
}
}

int main(){

int arr[]={1,2,3,4,5};

int n=sizeof(arr)/sizeof(arr[0]);

int d;
printf("\nEnter the value of d : ");
scanf("%d",&d);

printf("\nArray is : \n\n");
int i;
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}
getch();

printf("\nRotated array :\n");

//RotateArray(arr,n,d);
RotateArray1(arr,n,d);
getch();
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}




return 0;
}
