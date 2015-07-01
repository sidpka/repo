#include<stdio.h>
#include<conio.h>


void PrintDistinctElements(int* arr,int n){

int hash[100]={0};
int i;
for(i=0;i<n;i++){
if(hash[arr[i]]==0){
hash[arr[i]]=1;
printf("%d  ",arr[i]);
}
}


}

int main(){

int arr[]={2,1,3,2,4,1,5};
int n=sizeof(arr)/sizeof(arr[0]);

PrintDistinctElements(arr,n);







return 0;
}
