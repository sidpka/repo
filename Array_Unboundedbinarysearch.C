#include<stdio.h>
#include<conio.h>


int Fun(int x){

return (x*x -10*x-20);

}


int BS(int high,int low){

while(high>=low){
if(Fun(low)>0){
return low;
}

int mid=(low+high)/2;

if((mid==0 || Fun(mid-1)<=0)&& (mid==high || Fun(mid)>0)){
return mid;
}else if(Fun(mid)<0){
return BS(high,mid+1);
}else{
return BS(mid-1,low);
}


}

}

int FindFirstPositive(){

if(Fun(0)>0){
return 0;
}

int i=1;

while(Fun(i)<=0){
i*=2;
}

//printf("%d",i);

return BS(i,i/2);


}

int main(){

int firstPositive=FindFirstPositive();

printf("\nFirst positive : %d",firstPositive);

return 0;
}
