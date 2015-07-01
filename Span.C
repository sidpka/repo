#include<stdio.h>
#include<stdio.h>

#include<conio.h>
#include<stdlib.h>

void FindSpan(int A[],int S[]){
S[0]=1;

int i,j,sum;

for(i=1;i<5;i++){
j=1;

while(j<=i && A[i]>A[i-j]){
j=j+1;
}

S[i]=j;
}
printf("\nSpan is ...\n\n");
for(i=0;i<5;i++){
printf("%d   ",S[i]);
}

}


int main(){


int S[5];
int A[5]={6,3,4,5,2};

//FindSpan(A,S);








return 0;
}
