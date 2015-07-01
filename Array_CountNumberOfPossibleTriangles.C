#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b){

return (*(int*)a-*(int*)b);

}

int FindTriangles(int* arr,int n){

qsort(arr,n,sizeof(int),cmp);

int i;
/*
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}
*/

int left,right;
int cnt=0;
int j;
int k;
for(i=0;i<n-2;i++){

k=i+2;

for(j=i+1;j<n-1;j++){

while(k<n && arr[i]+arr[j]>arr[k]){

k++;

}
cnt+=k-j-1;
}

}

return cnt;

}


int main(){

int arr[]={4,6,3,7};
int n=sizeof(arr)/sizeof(arr[0]);

printf("\nNo of triangles : %d",FindTriangles(arr,n));








return 0;
}
