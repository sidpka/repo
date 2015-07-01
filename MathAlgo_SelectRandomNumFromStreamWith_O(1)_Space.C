#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>


void FindStream(int stream[],int n){

int tmp;

tmp=stream[0];

srand(time(NULL));

int i;
int j;

for(i=1;i<n;i++){

j=rand()%(i+1);
if(j==0){
tmp=stream[i];
}


}

printf("\nRandom number is : %d",tmp);



}

int main(){

int stream[]={1, 2, 3, 4};

int n=sizeof(stream)/sizeof(stream[0]);

FindStream(stream,n);




return 0;
}
