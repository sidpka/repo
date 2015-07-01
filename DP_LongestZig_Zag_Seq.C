#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int LZZS(int* arr,int n){

int* dp=(int*)malloc(sizeof(int)*n);
int* sign=(int*)malloc(sizeof(int)*n);

int i;

for(i=0;i<n;i++){
sign[i]=0;
dp[i]=1;
}

int j;

int currentSign;


for(i=1;i<n;i++){


for(j=i-1;j>=0;j--){

currentSign=sign[j];

if(currentSign==0 || (currentSign<0 && (arr[i]-arr[j]) >0) || (currentSign>0 && (arr[i]-arr[j]) <0)){

dp[i]=dp[j]+1;
sign[i]=arr[i]-arr[j];
break;

}

}



}

/*
for(i=0;i<n;i++){
printf("%d  ",dp[i]);
}

getch();
*/

return dp[n-1];

}

int main(){


int arr[]={1,17,5,10,13,15,10,5,16,8};

int n=sizeof(arr)/sizeof(arr[0]);

printf("\nLongest zig-zag seq : %d",LZZS(arr,n));






return 0;
}
