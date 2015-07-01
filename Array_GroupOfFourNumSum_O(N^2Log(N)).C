#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct Pair{

int fIndex;
int sIndex;
int sum;

};
typedef struct Pair pairs;

int cmp(const void* a,const void* b){

return ((*(pairs*)a).sum-(*(pairs*)b).sum);


}



int IsCommonElm(pairs a,pairs b){

if(a.fIndex==b.fIndex || a.sIndex==b.sIndex || a.fIndex==b.sIndex || a.sIndex==b.fIndex){
return 1;
}

return 0;
}

void FindAllGroupWithSum(int* arr,int n,int sum){

const int m=n*(n-1)/2;
//pairs* aux=(pairs*)malloc(sizeof(pairs)*m);
pairs aux[m];
int i,j;
int index=0;
for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
aux[index].sum=arr[i]+arr[j];
aux[index].fIndex=i;
aux[index].sIndex=j;
index++;
}
}

/*
for(i=0;i<m;i++){
printf("%d  ",aux[i].sum);
}

*/

qsort(aux,m,sizeof(pairs),cmp);

i=0;
j=m-1;
int tmpSum;
while(i<j){
tmpSum=aux[i].sum+aux[j].sum;

if(sum==tmpSum && !IsCommonElm(aux[i],aux[j])){
    //printf("\nHere");
printf("\n%d  %d  %d  %d",arr[aux[i].fIndex],arr[aux[i].sIndex],arr[aux[j].fIndex],arr[aux[j].sIndex]);
i++;
j--;
}else if(sum<tmpSum){
j--;
}else{
i++;
}
}
}


int main(){

int arr[]={10,2,3,4,5,9,7,8};

int n=sizeof(arr)/sizeof(arr[0]);

int sum=23;

FindAllGroupWithSum(arr,n,sum);

return 0;
}
