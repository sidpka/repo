#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



struct Box{

int h;
int w;
int d;
};

typedef struct Box Boxes;

int max(int a,int b){

return a>b?a:b;
}

int min(int a,int b){

return a<b?a:b;
}

int cmp(const void* a,const void* b){


return ((*(Boxes*)b).w)*((*(Boxes*)b).d)-
         ((*(Boxes*)a).w)*((*(Boxes*)a).d);
}

int FindMaxHeight(Boxes arr[],int n){

Boxes rota[3*n];

int i;
int index=0;
for(i=0;i<n;i++){
rota[index++]=arr[i];

rota[index].h=arr[i].d;

rota[index].d=max(arr[i].h,arr[i].w);
rota[index].w=min(arr[i].h,arr[i].w);

index++;

rota[index].h=arr[i].w;

rota[index].d=max(arr[i].h,arr[i].d);
rota[index].w=min(arr[i].h,arr[i].d);
index++;

}
n=3*n;

/*
printf("\nBefore\n");
for(i=0;i<n;i++){
printf("\n%d  %d  %d",rota[i].h,rota[i].w,rota[i].d);
}
*/
qsort(rota,n,sizeof(Boxes),cmp);

/*
printf("\nAfter\n");
for(i=0;i<n;i++){
printf("\n%d  %d  %d",rota[i].h,rota[i].w,rota[i].d);
}
*/

int j;

int mst[n];

for(i=0;i<n;i++){
mst[i]=rota[i].h;
}

for(i=1;i<n;i++){
for(j=0;j<i;j++){

if(rota[i].d<rota[j].d && rota[i].w<rota[j].w && mst[i]<mst[j]+rota[i].h){
mst[i]=mst[j]+rota[i].h;
}
}
}

int maxHeight=0;

for(i=0;i<n;i++){

if(mst[i]>maxHeight){
maxHeight=mst[i];
}

}


return maxHeight;
}

int main(){

Boxes arr[]={{4, 6, 7},{1, 2, 3},{4, 5, 6},{10, 12, 32}};

int n=sizeof(arr)/sizeof(arr[0]);

int maxHeight=FindMaxHeight(arr,n);

printf("\nMax possible height of stack : %d",maxHeight);





return 0;
}
