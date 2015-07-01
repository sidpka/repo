#include<stdio.h>
#include<conio.h>

int CheckIfDuplicate(int* arr,int n,int k){

int hash[100];
int i;

for(i=0;i<100;i++){
hash[i]=0;
}

for(i=0;i<n;i++){

if(hash[arr[i]]){
return 1;
}

hash[arr[i]]=1;

if(i>=k){
hash[arr[i-k]]=0;
}

}


return 0;
}

int main(){


int arr[]={1,2,3,4,1,2,3,4};

int n=sizeof(arr)/sizeof(arr[0]);
int K=3;
int flag=CheckIfDuplicate(arr,n,K);

if(flag){
printf("\nYes");
}else{
printf("\nNo");
}







return 0;
}
