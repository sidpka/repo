#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct SuffixArray{
int index;
int rank[2];
};

typedef struct SuffixArray suffix;


int cmp(const void* a,const void* b){
return ((*(suffix*)a).rank[0]==(*(suffix*)b).rank[0])?
       ((*(suffix*)a).rank[1]<(*(suffix*)b).rank[1] ?
        0:1):
        ((*(suffix*)a).rank[0]<(*(suffix*)b).rank[0] ? 0:1);
}


/*
int cmp(const void* a,const void* b)
{

    return ((*(suffix*)a).rank[0] == (*(suffix*)b).rank[0])? ((*(suffix*)a).rank[1] < (*(suffix*)b).rank[1] ?1: 0):
               ((*(suffix*)a).rank[0] < (*(suffix*)b).rank[0] ?1: 0);
}
*/
int* GetSortedIndex(char* text,int n){

int i;
suffix array[n];




for(i=0;i<n;i++){
array[i].index=i;
array[i].rank[0]=text[i]-'a';
array[i].rank[1]=((i+1)< n) ? (text[i+1]-'a'):-1;
}
/*
for(i=0;i<n;i++){
printf("\n%d %d %d",array[i].index,array[i].rank[0],array[i].rank[1]);
}

getch();
*/
qsort(array,n,sizeof(suffix),cmp);
/*
for(i=0;i<n;i++){
printf("%d ",array[i].index);
}
*/

int k;

int ind[n];

for(k=4;k<2*n;k*=2){
int rank=0;
int prevRank=array[0].rank[0];
array[0].rank[0]=rank;
ind[array[0].index]=0;

for(i=1;i<n;i++){
if(array[i].rank[0]==prevRank && array[i].rank[1]==array[i-1].rank[1]){

    prevRank=array[i].rank[0];
    array[i].rank[0]=rank;

}else{
prevRank=array[i].rank[0];
array[i].rank[0]=++rank;
}
ind[array[i].index]=i;
}

for(i=0;i<n;i++){

int nextIndex=array[i].index+k/2;

array[i].rank[1]=(nextIndex<n)? array[ind[nextIndex]].rank[0]:-1;

}
qsort(array,n,sizeof(suffix),cmp);

}
int* suffxArray=(int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++){
//printf("%d  ",array[i].index);
suffxArray[i]=array[i].index;
}
return suffxArray;
}

int main(){

char text[]="banana";

int len=strlen(text);
int* result=GetSortedIndex(text,len);
int i;
for(i=0;i<len;i++){
printf("%d  ",result[i]);
}

return 0;
}
