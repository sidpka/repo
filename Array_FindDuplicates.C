#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

//Find Duplicates in O(n) time and O(1) extra space

void FindDuplicates(int* arr,int n){

int* tmp=(int*)malloc(sizeof(int)*n);

int i;

for(i=0;i<n;i++){
tmp[i]=arr[i];
}





//this can not handle case when a number appears more than 2
/*
for(i=0;i<n;i++){
if(tmp[abs(tmp[i])]>=0){
tmp[abs(tmp[i])]=-tmp[abs(tmp[i])];
}else{
printf("%d  ",abs(tmp[i]));
}
}

*/

//This works for more than 2 repetitions
for(i=0;i<n;i++){
if(tmp[abs(tmp[i])]>=0){
tmp[abs(tmp[i])]=-tmp[abs(tmp[i])];
}else if(tmp[abs(tmp[i])]!=INT_MIN){
printf("%d  ",abs(tmp[i]));
tmp[abs(tmp[i])]=INT_MIN;
}
}

}

int main(){
int arr[]={1,2,3,1,1,2,2,3,4,3,0,1,0};
int n=sizeof(arr)/sizeof(arr[0]);
FindDuplicates(arr,n);
return 0;
}
