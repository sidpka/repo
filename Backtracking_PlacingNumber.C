#include<stdio.h>
#include<conio.h>


int FindFix_Util(int arr[],int cur,int n){

if(cur==0){
return 1;
}

int i;

for(i=0;i<2*n-cur-1;i++){

if(arr[i]==0 && arr[i+cur+1]==0){

arr[i]=cur;
arr[i+cur+1]=cur;

if(FindFix_Util(arr,cur-1,n)){
return 1;
}else{
arr[i]=0;
arr[i+cur+1]=0;
}


}
}

return 0;

}

void FindFix(int n){


int arr[2*n];

int i;

for(i=0;i<2*n;i++){
arr[i]=0;
}

if(FindFix_Util(arr,n,n)){
for(i=0;i<2*n;i++){
printf("%d  ",arr[i]);
}
}else{
printf("\nNo fix");
}


}

int main(){


int n=3;
FindFix(n);





return 0;
}
