#include<stdio.h>
#include<conio.h>


int CountSetBits_Util(int n){

if(n<=0){
return 0;
}

return ((n&1)?1:0) + CountSetBits_Util(n/2);
}

int CountSetBits(int n){
int count=0;

int i;

for(i=1;i<=n;i++){
count+=CountSetBits_Util(i);
}

return count;
}

int PowerOf2(int n){

if(n && !(n & (n-1)) ){
return 1;
}

return 0;
}

int CountSetBits2(int n){
    //printf("\nn : %d",n);
int count=0;
int prevNumCount=0;

int i;

for(i=1;i<=n;i++){

if(!(i&1)){
    //printf("\nHere for : %d",i);
if(PowerOf2(i)){
   // printf("\nHere for : %d",i);
prevNumCount=1;
//count+=1;
}//else{
//count+=prevNumCount;
//}
}else{
prevNumCount+=1;
//count+=prevNumCount;
}

count+=prevNumCount;
}

return count;
}

int main(){

int n=6;
//printf("\nNo of set bits : %d",CountSetBits(n));
printf("\nNo of set bits : %d",CountSetBits2(n));


return 0;
}
