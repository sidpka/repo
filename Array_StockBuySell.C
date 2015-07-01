#include<stdio.h>
#include<conio.h>

struct Interval{
int buy;
int sell;
};

typedef struct Interval interval;

void MakeProfit(int* arr,int n){
if(n==1){
return;
}
interval stock[n/2+1];

int i=0;
int count=0;
while(i<n-1){

while((i<n-1) && arr[i+1]<arr[i]){
i++;
}

if(i==n){
break;
}

stock[count].buy=i++;

while((i<n) && arr[i]>=arr[i-1]){
i++;
}

stock[count].sell=i-1;

count++;

}

if(count==0){
printf("\nProfit cant be made ");
}else{
for(i=0;i<count;i++){
printf("\nBuy date : %d  Sell date : %d",stock[i].buy,stock[i].sell);
}
}

}


int main(){

    int arr[]={100,180,260,310,40,535,695};

    int n=sizeof(arr)/sizeof(arr[0]);

    MakeProfit(arr,n);










return 0;
}
