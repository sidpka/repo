#include<stdio.h>
#include<conio.h>

struct Elements{
int elm;
int count;
};
typedef struct Elements Element;

void FindNDK(int* arr,int n,int k){

Element cArr[k-1];

int i;

for(i=0;i<k-1;i++){
cArr[i].count=0;
}

int j;
int l;

for(i=0;i<n;i++){

for(j=0;j<k-1;j++){
if(cArr[j].elm==arr[i]){
cArr[j].count++;
break;
}
}

if(j==k-1){

for(j=0;j<k-1;j++){
if(cArr[j].count==0){
cArr[j].elm=arr[i];
cArr[j].count=1;
break;
}
}

if(j==k-1){

for(j=0;j<k-1;j++){
cArr[j].count--;
}

}

}
}
/*
for(i=0;i<k-1;i++){
printf("\n%d  %d",cArr[i].elm,cArr[i].count);
}
getch();
*/
int freq;
for(j=0;j<k-1;j++){
freq=0;
for(i=0;i<n;i++){
if(arr[i]==cArr[j].elm){
freq++;
}
}
//printf("\nfreq of : %d is : %d",cArr[i].elm,freq);
if(freq>(n/k)){
printf("%d  ",cArr[j].elm);
}
}
}

int main(){

int arr[]={3,1,2,2,2,1,4,3,3};

int n=sizeof(arr)/sizeof(arr[0]);
int k=4;

FindNDK(arr,n,k);






return 0;
}
