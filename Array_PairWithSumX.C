#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b){
return *(int*)a-*(int*)b;
}

int FindIfPairExists(int* arr,int x,int n){

int i=0;
int j=n-1;

while(i<j){
if(arr[i]+arr[j]==x){
return 1;
}else if(arr[i]+arr[j]<x){
i++;
}else{
j--;
}

}

return 0;



}


int FindUsingHashMap(int* arr,int x,int n){

int hashMap[10000]={0};

//printf("\n%d",hashMap[100]);

int i;

for(i=0;i<n;i++){
if(arr[i]<x && hashMap[x-arr[i]]==1){
return 1;
}
hashMap[arr[i]]=1;
}

return 0;



}



int main(){
int n;
printf("\nEnter the number of elements in the array : ");
scanf("%d",&n);
int i;
int* arr=(int*)malloc(sizeof(int)*n);

printf("\nEnter the elements of the array : ");

for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}

printf("\nArray is : ");
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}
qsort(arr,n,sizeof(int),cmp);
printf("\nSorted array is :  ");
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}

printf("\nEnter a number to see if a pair adds up to this : ");
int x;
scanf("%d",&x);
//int result=FindIfPairExists(arr,x,n);

int result=FindUsingHashMap(arr,x,n);

if(result){
printf("\nYes");
}else{
printf("\No");
}






return 0;
}
