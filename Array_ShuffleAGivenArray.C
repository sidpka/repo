#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

void Swap(int* arr,int left,int right){

int tmp=arr[left];
arr[left]=arr[right];
arr[right]=tmp;

}


void Randomize(int* arr,int n){


int i,j;
//such that different random numbers are generated when compiled another time... so srand
srand(time(NULL));
for(i=n-1;i>0;i--){
j=rand()%(i+1);
printf("\nRand is : %d  ",j);
Swap(arr,i,j);
}

}



int main(){


int arr[]={2,1,4,6,5};
int n=sizeof(arr)/sizeof(arr[0]);

printf("\nBefore randomizing :\n\n");
int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}

Randomize(arr,n);

printf("\nAfter updating\n\n");

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}











return 0;
}
