#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>


int min(int a,int b){
return a<b?a:b;
}

int Left(int i){
return 2*i+1;
}

int Right(int i){
return 2*i+2;
}

int FindMin(int* arr,int start){
int i=start-1;
while(i>=0){
arr[i]=min(arr[Left(i)],arr[Right(i)]);
i--;
}

return arr[0];
}


int FindSMin(int* arr,int start){

int i=0;

int sMin=INT_MAX;
int tmp;
int minE=arr[0];
while(i<=start-1){
if(arr[Left(i)]==minE){
tmp=arr[Right(i)];
i=Left(i);
}else{
tmp=arr[Left(i)];
i=Right(i);
}
if(tmp<sMin){
sMin=tmp;
}
}

return sMin;
}

int main(){

int arr[]={3,6,2,7,1,4};
int n=sizeof(arr)/sizeof(arr[0]);

int height=ceil(log2(n));
//printf("%d",height);
int m=(int)pow(2,height+1)-1;
//printf("\n%d",m);
int* tArr=(int*)malloc(sizeof(int)*m);

int i;
int start=(int)pow(2,height)-1;

for(i=0;i<m;i++){
tArr[i]=INT_MAX;
}

for(i=0;i<n;i++){
tArr[i+start]=arr[i];
}

int min=FindMin(tArr,start);

printf("Min is : %d",min);

int sMin=FindSMin(tArr,start);

printf("\nSecond Min is : %d",sMin);



return 0;
}
