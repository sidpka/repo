#include<stdio.h>
#include<conio.h>
#include<limits.h>

void GetMinUnsorted(int* arr,int n){

int s=0;
int e=n-1;
//Finding candidate unsorted array
while(s<n){
if(arr[s]>arr[s+1]){
break;
}else{
s++;
}
}

while(e>0){
if(arr[e]<arr[e-1]){
break;
}else{
e--;
}
}

//printf("\nIndex of unsorted subarray : %d and %d",s,e);

int min=INT_MAX;
int max=INT_MIN;
int i;
for(i=s;i<e;i++){

if(arr[i]<min){
min=arr[i];
}

if(arr[i]>max){
max=arr[i];
}
}


//printf("\nMin is : %d and max is : %d",min,max);

for(i=0;i<s;i++){
if(arr[i]>min){
s=i;
break;
}
}

for(i=n-1;i>e;i--){
if(arr[i]<max){
e=i;
break;
}
}
printf("\nIndex of unsorted subarray : %d and %d",s,e);

}

int main(){

int arr[]={10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};

int n=sizeof(arr)/sizeof(arr[0]);

printf("\nPress enter to find min length unsorted subarray :\n");
getch();
GetMinUnsorted(arr,n);
getch();


return 0;
}
