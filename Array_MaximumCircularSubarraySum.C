#include<stdio.h>
#include<conio.h>


int FindMaxSum(int* arr,int n){


int max=arr[0];

int tmpMax=arr[0];

int sum;

int i;

int j;

for(i=0;i<n;i++){
j=(i+1)%n;
sum=arr[i];
tmpMax=sum;
while(j!=i){
sum+=arr[j];
if(sum>tmpMax){
tmpMax=sum;
}

j=(j+1)%n;

}
if(tmpMax>max){
max=tmpMax;
}
}

return max;
}

int main(){


//int arr[]={8,-8,9,-9,10,-11,12};

int arr[]={10,-3,-4,7,6,5,-4,-1};

int n=sizeof(arr)/sizeof(arr[0]);
//O(n^2)
int result=FindMaxSum(arr,n);

printf("\nMax sum is : %d",result);





return 0;
}


