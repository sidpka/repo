#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void FindNth(int n){

//char* arr[n+1];

char** arr=(char**)malloc(sizeof(char*)*(n+1));

int j;

for(j=0;j<=n;j++){
arr[j]=(char*)malloc(sizeof(char)*20);
}

arr[0]="";

int size=1;
int m=1;
int i;

//strcpy(arr[size+1],"3");



while(size<=n){


for(i=0;i<m && (size+i<=n) ; i++){
arr[size+i][0]='\0';
strcpy(arr[size+i],"3");
strcat(arr[size+i],arr[size-m+i]);
//printf("\n%s",arr[size+i]);
}


for(i=0;i<m && (size+i+m<=n) ; i++){
arr[size+m+i][0]='\0';
strcpy(arr[size+m+i],"4");
strcat(arr[size+m+i],arr[size-m+i]);
//printf("\n%s",arr[size+i]);
}

m=m<<1;
size=size+m;
}



printf("\n%dth number is : %s",n,arr[n]);
}








int main(){

int n=5;

FindNth(n);






return 0;
}
