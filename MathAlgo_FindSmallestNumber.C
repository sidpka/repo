#include<stdio.h>
#include<conio.h>
#define max 100

void FindSmallestDigit(int n){

int arr[max]={0};
int tmp=n;
if(n<10){
printf("\nSmallest word whose digits sum upto : %d is : ",tmp);
printf("\n%d",n+10);
return;
}



//arr[0]=1;
int index=0;


int i;

for(i=9;i>1;i--){

while(n%i==0){
arr[index++]=i;
n/=i;
}

}

if(n>10){
printf("\nNot possible");
}

printf("\nSmallest word whose digits sum upto : %d is : ",tmp);
for(i=index-1;i>=0;i--){
printf("%d",arr[i]);
}

}


int main(){

//int n=36;
int n=100;
FindSmallestDigit(n);



return 0;
}
