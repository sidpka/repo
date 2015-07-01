#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b){


return *(int*)a-*(int*)b ;
}

void FindNextLargest(int arr[],int n){

int i;

for(i=n-1;i>0;i--){
if(arr[i]>arr[i-1]){
break;
}
}
if(i==0){
printf("\nNot possible");
return;
}
/*
int tmp=arr[i];
arr[i]=arr[i-1];
arr[i-1]=tmp;
*/
int tmp=arr[i-1];
int j;
int min=i;

for(j=n-1;j>=i;j--){
if(arr[j]>tmp && arr[j]<arr[min]){
min=j;
}

}

/*
printf("\nMin :%d",arr[min]);
getch();
*/

arr[i-1]=arr[min];
arr[min]=tmp;




qsort(arr+i,n-i,sizeof(int),cmp);

printf("\nNext greater number is :   ");
for(i=0;i<n;i++){
printf("%d",arr[i]);
}

}

int main(){


//int arr[]={4,3,2,5,1};
//int arr[]={2,1,8,7,6,5};

//int arr[]={1,2,3,4};

//int arr[]={4,3,2,1};

int arr[]={5,3,4,9,7,6};

int n=sizeof(arr)/sizeof(arr[0]);
FindNextLargest(arr,n);





return 0;
}
