#include<stdio.h>
#include<conio.h>


int min(int a,int b){
return a<b?a:b;
}

int max(int a,int b){
return a>b?a:b;
}

int FindMaxProd(int* arr,int n){


int i;

int tmpMax=1;
int tmpMin=1;
int maxTot=1;

for(i=0;i<n;i++){
    //printf("\ntmpMax : %d",tmpMax);
if(arr[i]>0){
tmpMax=tmpMax*arr[i];
tmpMin=min(tmpMin*arr[i],1);
}else if(arr[i]==0){
tmpMax=1;
tmpMin=1;
}else{
int tmp=tmpMax;
tmpMax=max(tmpMin*arr[i],1);
tmpMin=tmp*arr[i];
}

if(maxTot<tmpMax){
maxTot=tmpMax;
}
}


return maxTot;

}

int main(){


int arr[]={6, -3, -10, 0, 2};

int n=sizeof(arr)/sizeof(arr[0]);

int maxProd=FindMaxProd(arr,n);

printf("\nMax prod : %d",maxProd);









return 0;
}
