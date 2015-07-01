#include<stdio.h>
#include<conio.h>

int max(int a,int b){
return a>b?a:b;
}

int FindSum(int* arr,int n){

int tmpIn;
int tmpOut;

int in=arr[0];
int out=0;

int i;

for(i=1;i<n;i++){
tmpIn=in;
tmpOut=out;
in=tmpOut+arr[i];
out=max(tmpIn,tmpOut);
}

return max(in,out);
}

int main(){

int arr[]={5,5,10,40,50,35};

int n=sizeof(arr)/sizeof(arr[0]);

int sum=FindSum(arr,n);

printf("\nSum of subarray with no adjacent element selected : %d",sum);
getch();


return 0;
}
