#include<stdio.h>
#include<conio.h>

void Segragate(int* arr,int n){

int i;
int count=0;
for(i=0;i<n;i++){
if(arr[i]&&1){
count++;
}
}

printf("\nCount is : %d",count);

for(i=0;i<n;i++){
if(count){
arr[i]=1;
count--;
}else{
arr[i]=0;
}
}
}

void Segragate2(int* arr,int n){

int left=0;
int right=n-1;

while(left<right){
if(arr[left]==0){
left++;
}
if(arr[right]==1){
right--;
}

if(arr[left]!=0 && arr[right]!=1){
arr[left]=0;
arr[right]=1;
left++;
right--;
}
}
}


int main(){

int arr[]={1,1,0,1,0,1,0,0};

int n=sizeof(arr)/sizeof(arr[0]);
//Naive
//Segragate(arr,n);
//printf("\nSegragated \n\n");

//Improved
Segragate2(arr,n);
int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}









return 0;
}
