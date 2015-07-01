#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE (1<<16)

#define Group_A(x) x,x+1,x+1,x+2
#define Group_B(x) Group_A(x),Group_A(x+1),Group_A(x+1),Group_A(x+2)
#define Group_C(x) Group_B(x),Group_B(x+1),Group_B(x+1),Group_B(x+2)


#define Meta_LookUp(Parameter)\
Group_##Parameter(0),\
Group_##Parameter(1),\
Group_##Parameter(2),\
Group_##Parameter(3)\


int CountBits(int arr[],int n){

int count=0;

static unsigned char const lookUp[]={ Meta_LookUp(C) };

int i;
unsigned char* pData=NULL;
for(i=0;i<n;i++){
pData=(unsigned char*)&arr[i];
count+=lookUp[pData[0]];
count+=lookUp[pData[1]];
count+=lookUp[pData[2]];
count+=lookUp[pData[3]];
}




return count;
}


int main(){

int arr[SIZE];

int i;

srand(unsigned(time(0)));

for(i=0;i<SIZE;i++){
arr[i]=rand();
}

//int n=sizeof(arr)/sizeof(arr[0]);
printf("\nNumber of set bits : %d",CountBits(arr,SIZE));





return 0;
}
