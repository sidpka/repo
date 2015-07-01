#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<stdlib.h>


void FindTugOfWar_Util(int arr[],int n,int m,int buffer[],int count,int* diff,int result[]){

if(n<=0){
return;
}

if(count==m/2){

int firstSet=0;
int secondSet=0;

int i;

for(i=0;i<m;i++){
if(buffer[i]){
firstSet+=arr[i];
}else{
secondSet+=arr[i];
}
}

int var=abs(firstSet-secondSet);

if(var<*diff){
*diff=var;

for(i=0;i<m;i++){
result[i]=buffer[i];
}

}

return;
}

buffer[n-1]=1;
FindTugOfWar_Util(arr,n-1,m,buffer,count+1,diff,result);
buffer[n-1]=0;
FindTugOfWar_Util(arr,n-1,m,buffer,count,diff,result);



}

void FindTugOfWar(int arr[],int n){


int buffer[n];

int i;
int result[n];

for(i=0;i<n;i++){
buffer[i]=0;
}

int diff=INT_MAX;
int minDiff=INT_MAX;

FindTugOfWar_Util(arr,n,n,buffer,0,&diff,result);

printf("\nMinimum diff : %d",diff);

printf("\nFirst subset \n");
for(i=0;i<n;i++){
if(result[i]){
printf("%d  ",arr[i]);
}
}
printf("\nSecond subset\n");
for(i=0;i<n;i++){
if(!result[i]){
printf("%d  ",arr[i]);
}
}



}

int main(){


//int arr[]={3,4,5,-3,100,1,89,54,23,20};

int arr[]={23,45,-34,12,0,98,-99,4,189,-1,4};

int n=sizeof(arr)/sizeof(arr[0]);

FindTugOfWar(arr,n);







return 0;
}
