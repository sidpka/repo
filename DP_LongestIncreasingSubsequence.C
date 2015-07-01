#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int LSI(int* arr,int n){


int* lis=(int*)malloc(sizeof(int)*n);

int i;

for(i=0;i<n;i++){
lis[i]=1;
}

int j;

for(i=1;i<n;i++){

for(j=0;j<i;j++){

if(arr[j]<arr[i] && lis[j]+1>lis[i]){
lis[i]=lis[j]+1;
}

}

}

/*

for(i=0;i<n;i++){
printf("%d  ",lis[i]);
}

getch();
*/
int max=1;

for(i=0;i<n;i++){
if(lis[i]>max){
max=lis[i];
}
}

return max;


}

int main(){


int arr[]={5,3,4,7,6,9};
int n=sizeof(arr)/sizeof(arr[0]);

printf("\nLongest increasing subsequence : %d",LSI(arr,n));



return 0;
}
