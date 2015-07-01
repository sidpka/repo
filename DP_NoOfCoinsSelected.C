#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define INT_MAX 99999
int CountCoins(int* arr,int n,int sum){
int* Min=(int*)malloc(sizeof(int)*(sum+1));
int i;

for(i=1;i<=sum;i++){
Min[i]=INT_MAX;
}

int j;

Min[0]=0;

for(i=1;i<=sum;i++){

for(j=0;j<n;j++){

if(arr[j]<=i && Min[i-arr[j]]+1<Min[i]){
Min[i]=Min[i-arr[j]]+1;
}

}

}
/*
for(i=0;i<=sum;i++){
printf("%d  ",Min[i]);
}

getch();
*/
return Min[sum];
}

int main(){


int coins[]={2,3,5};
int n=sizeof(coins)/sizeof(coins[0]);

int sum=11;

int result=CountCoins(coins,n,sum);

if(result==INT_MAX){
printf("\nSum : %d not possible from the given coins ",sum);
}else{
printf("No of coins needed : %d",result);
}






return 0;
}
