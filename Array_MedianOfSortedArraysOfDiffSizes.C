#include<stdio.h>
#include<conio.h>



int max(int a,int b){
return a>b?a:b;
}

int min(int a,int b){
return a<b?a:b;
}

int GetMedian(int* arr,int n){
if(n%2==0){
return (arr[n/2]+arr[n/2-1])/2;
}else{
return arr[n/2];
}
}

float MO2(int a,int b){

return (a+b)/2.0;
}

float MO3(int a,int b,int c){

return (a+b+c)-max(a,max(b,c))-min(a,min(b,c));

}

float MO4(int a,int b,int c,int d){

int maxi=max(a,max(b,max(c,d)));
int mini=min(a,min(b,min(c,d)));

return ((a+b+c+d)-maxi-mini)/2.0;
}

float FindMedianUtil(int* arr1,int n,int* arr2,int m){

if(n==1){

if(m==1){
return MO2(arr1[0],arr2[0]);
}

if(m&1){
return MO2(arr2[m/2],MO3(arr1[0],arr2[m/2-1],arr2[m/2+1]));
}

return MO3(arr1[0],arr2[m/2],arr2[m/2-1]);

}

if(n==2){

if(m==2){

return MO4(arr1[0],arr1[1],arr2[0],arr2[1]);
}

if(m&1){

return MO3(arr2[m/2],max(arr1[0],arr2[m/2-1]),min(arr1[1],arr2[m/2+1]));

}

return MO4(arr2[m/2],arr2[m/2-1],max(arr1[0],arr2[m/2-2]),min(arr1[1],arr2[m/2+1]));

}

int m1=(n-1)/2;
int m2=(m-1)/2;

if(arr1[m1]<arr2[m2]){
return FindMedianUtil(arr1+m1,n/2+1,arr2,m-m1);
}
return FindMedianUtil(arr1,n/2+1,arr2+m1,m-m1);

}


float FindMedian(int* arr1,int n,int* arr2,int m){

if(n>m){
return FindMedianUtil(arr2,m,arr1,n);
}
return FindMedianUtil(arr1,n,arr2,m);

}





int main(){

int arr1[]={900};
int arr2[]={5,8,10,20};

int n=sizeof(arr1)/sizeof(arr1[0]);
int m=sizeof(arr2)/sizeof(arr2[0]);

float median=FindMedian(arr1,n,arr2,m);
printf("\nMedian is : %f",median);

return 0;
}
