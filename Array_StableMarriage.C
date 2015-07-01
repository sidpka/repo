#include<stdio.h>
#include<conio.h>
#define N 4


int PrefersEngaged(int arr[2*N][N],int lady,int fiance,int dude){


int i;

for(i=0;i<N;i++){
if(arr[lady][i]==fiance){
return 1;
}

if(arr[lady][i]==dude){
return 0;
}

}




}


void StableMarriage(int arr[2*N][N]){

int wEngDetail[N];
int mEngStatus[N];

int i;

for(i=0;i<N;i++){
wEngDetail[i]=-1;
mEngStatus[i]=0;
}

int freeMenCount=N;
int m,w,j;


while(freeMenCount>0){

for(i=0;i<N;i++){
if(mEngStatus[i]==0){
m=i;
break;
}
}

for(j=0;j<N;j++){

w=arr[m][j];

if(wEngDetail[w-N]==-1){
wEngDetail[w-N]=m;
mEngStatus[m]=1;
freeMenCount--;
break;
}else{
int m1=wEngDetail[w-N];

if(PrefersEngaged(arr,w,m1,m)==0){
wEngDetail[w-N]=m;
mEngStatus[m]=1;
mEngStatus[m1]=0;
break;
}
}


}



}



printf("\nWoman\tMan");
for(i=0;i<N;i++){
printf("\n%d\t%d",i+N,wEngDetail[i]);
}


}

int main(){

int arr[2*N][N]={{7,5,6,4},
                 {5,4,6,7},
                 {4,5,6,7},
                 {4,5,6,7},
                 {0,1,2,3},
                 {0,1,2,3},
                 {0,1,2,3},
                 {0,1,2,3},

            };


StableMarriage(arr);








return 0;
}
