#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void FindRepeating(int* arr,int n){
if(n<2){
printf("\nInvalid array size \n");
return;
}

int tmp1,tmp2,tmpR;

tmp1=0;
tmp2=0;
tmpR=0;
int i;
for(i=0;i<n+2;i++){
tmp1=tmp1^arr[i];
}

for(i=1;i<=n;i++){
tmp2=tmp2^i;
}

tmpR=tmp1^tmp2;
//printf("\nResult : %d",tmpR);

// ~tmpR is same as doing -tmpR

int setBit=tmpR & (-tmpR);

//printf("\nSet bit : %d",setBit);

int group1=0;
int group2=0;

for(i=0;i<n+2;i++){
if(arr[i] & setBit){
group1=group1^arr[i];
}else{
group2=group2^arr[i];
}
}


for(i=1;i<=n;i++){
if(i & setBit){
group1=group1^i;
}else{
group2=group2^i;
}
}


printf("\nTwo repeating elements : %d and %d",group1,group2);

}

void FindRepeating2(int* arr,int n){

if(n<2){
printf("\nInvalid input array \n");
}

for(i=0;i<n+2;i++){
if(arr[i]<0){
printf("%d  ",arr[i]);
}else{
arr
}
}


}

int main(){

int arr[]={1,2,3,1,2};

int n=sizeof(arr)/sizeof(arr[0]);
printf("\nPress enter to see two repeating elms : \n\n");
getch();
FindRepeating(arr,n-2);

printf("\nAnother method :\n\n");
FindRepeating2(arr,n-2);

return 0;
}
