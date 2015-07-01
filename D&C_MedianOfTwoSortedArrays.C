#include<stdio.h>
#include<conio.h>

int max(int a,int b){

return (a>b)?a:b;
}

int  min(int a,int b){

return (a<b)?a:b;
}

int Median(int arr[],int n){

if(n%2==0){
return (arr[n/2]+arr[n/2-1])/2;
}else{
return arr[n/2];
}


}

int FindMedian(int arr1[],int arr2[],int n){


if(n==1){

return (arr1[0],arr2[0])/2;
}

if(n==2){

return (max(arr1[0],arr2[0]),min(arr1[1],arr2[1]))/2;

}


int m1=Median(arr1,n);
int m2=Median(arr2,n);

if(m1==m2){

return m1;
}

else if(m1>m2){
    if(n%2==0){
    return FindMedian(arr1,arr2+n/2-1,n-n/2+1);
    }
return FindMedian(arr1,arr2+n/2,n/2);
}else{
    if(n%2==0){
    return FindMedian(arr1+n/2-1,arr2,n-n/2+1);
    }
return FindMedian(arr1+n/2,arr2,n/2);
}


}

int main(){
 int arr1[]={1,2,3,6};
 int arr2[]={4,6,8,10};
 int n=sizeof(arr2)/sizeof(arr2[0]);

 printf("\nMedian is : %d",FindMedian(arr1,arr2,n));


return 0;
}
