#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void* a,const void* b){

return ( *(char*)a-*(char*)b );
}

void Swap(char* a,char* b){

char tmp=*a;
*a=*b;
*b=tmp;

}

int FindNextLarge(char str[],char first,int low,int n){

int i;
int final=low;

for(i=low+1;i<n;i++){

if(str[i]>first && str[i]<str[final]){
final=i;
}

}



return final;
}

void FindReverse(char str[],int low,int high){

if(low<high){

Swap(&str[low],&str[high]);
low++;
high--;

}


}

void FindAll(char str[]){

int n=strlen(str);

int isFinished=0;

qsort(str,n,sizeof(char),cmp);
int first;
int second;
int i;

while(!isFinished){

printf("\n%s",str);

for(i=n-2;i>=0;i--){
if(str[i]<str[i+1]){
break;
}
}

if(i==-1){
isFinished=1;
}else{

second=FindNextLarge(str,str[i],i+1,n);
//printf("\n%d",second);


Swap(&str[i],&str[second]);

FindReverse(str,i+1,n-1);
//qsort(str+i+1,n-i-1,sizeof(char),cmp);

}



}

}

int main(){

char str[]="CAB";

FindAll(str);

return 0;
}
