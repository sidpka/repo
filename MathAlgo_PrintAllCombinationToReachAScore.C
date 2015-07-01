#include<stdio.h>
#include<conio.h>

void PrintAllCombinations_Util(int arr[],int m,int n,int buffer[],int index){

if(n==0){
int k;

for(k=0;k<index;k++){
printf("%d ",buffer[k]);
}
printf("\n");
}

if(n>0){

int i;

for(i=0;i<m;i++){
buffer[index]=arr[i];
PrintAllCombinations_Util(arr,m,n-arr[i],buffer,index+1);
}



}

}

void PrintAllCombinations(int arr[],int m,int n){


int buffer[n];

PrintAllCombinations_Util(arr,m,n,buffer,0);



}

int main(){


int arr[]={1,2,3};
int m=sizeof(arr)/sizeof(arr[0]);

int n=4;

PrintAllCombinations(arr,m,n);





return 0;

}
