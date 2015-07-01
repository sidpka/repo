#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

 //Moore's voting algorithm

int FindCandidate(int* arr,int n){

int i=0;
int majorityElm=0;
int count=1;
for(i=1;i<n;i++){
if(arr[majorityElm]==arr[i]){
count++;
}else{
count--;
if(count==0){
majorityElm=i;
count=1;
}
}

}


return arr[majorityElm];
}

void PrintMajorityElm(int* arr,int n,int candidate){

int count=0;
int i;

for(i=0;i<n;i++){
if(candidate==arr[i]){
count++;
}
}

if(count>n/2){
printf("\nMajority Elm is : %d",candidate);
}else{
printf("\nNONE");
}

}




int main(){

int n;
printf("\nEnter the number of elements : ");
scanf("%d",&n);

printf("\nEnter the elements of the array : ");
int* arr=(int*)malloc(sizeof(int)*n);
int i;

for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}

int candidate=FindCandidate(arr,n);

printf("\nCandidate is : %d",candidate);

PrintMajorityElm(arr,n,candidate);

return 0;
}
