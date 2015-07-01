#include<stdio.h>
#include<conio.h>


int FindDistinctPairs(int* arr,int n,int k){


int hash[1000]={0};
int i;
for(i=0;i<n;i++){

if(hash[arr[i]]==0){
hash[arr[i]]=1;
}

}

int count=0;

int x;

for(i=0;i<n;i++){
x=arr[i];

if(x-k>=0 && hash[x-k]){
count++;
}

if(x+k<n && hash[x+k]){
count++;
}

hash[x]=0;
}

return count;
}


int main(){


int arr[]={1,5,3,4,2};
int n=sizeof(arr)/sizeof(arr[0]);
int k=3;

printf("\nCount of distinct pairs with diff : %d is : %d",k,FindDistinctPairs(arr,n,k));






return 0;
}
