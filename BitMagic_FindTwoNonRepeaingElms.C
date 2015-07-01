#include<stdio.h>
#include<conio.h>

void CheckNonRepeatingElements(int arr[],int n){


int sum=0;

int i;

for(i=0;i<n;i++){
sum^=arr[i];
}

int setBit=sum& ~(sum-1);
//printf("\n\n%d",setBit);

int x=0;
int y=0;

for(i=0;i<n;i++){
if(arr[i]&setBit){
x^=arr[i];
}else{
y^=arr[i];
}
}


printf("\nx : %d",x);
printf("\ny : %d",y);

}

int main(){

int arr[]={1,2,3,4,5,1,2,3};
int n=sizeof(arr)/sizeof(arr[0]);

CheckNonRepeatingElements(arr,n);



return 0;
}
