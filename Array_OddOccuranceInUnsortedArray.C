#include<stdio.h>
#include<conio.h>

void FindOddOccurances(int* arr,int n){

int xor1,xor2,xor3;

int i;
xor1=0;
for(i=0;i<n;i++){
xor1=xor1^arr[i];
}

xor2=xor1&(-xor1);
xor3=0;
xor1=0;
for(i=0;i<n;i++){
if(arr[i]&xor2){
xor1=xor1^arr[i];
}else{
xor3=xor3^arr[i];
}
}

printf("\n%d and %d occur for odd no of times ",xor1,xor3);
}


int main(){


int arr[]={4, 4, 100, 5000, 4, 4, 4, 4, 100, 100};

int n=sizeof(arr)/sizeof(arr[0]);

printf("\nPress enter to find two numbers which occurs odd no of times : ");
FindOddOccurances(arr,n);





return 0;
}
