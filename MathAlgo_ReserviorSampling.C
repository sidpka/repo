#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>


void FindSampling(int arr[],int n,int k){

int buffer[k];

int i;

for(i=0;i<k;i++){
buffer[i]=arr[i];
}

int j;

srand(time(NULL));




for(i=k;i<n;i++){

j=rand()%(i+1);

if(j<k){
buffer[j]=arr[i];
}


}



printf("\reservior has \n");

for(i=0;i<k;i++){
printf("%d  ",buffer[i]);
}


}

int main(){

int arr[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

int n=sizeof(arr)/sizeof(arr[0]);
int k=5;
FindSampling(arr,n,k);



return 0;
}
