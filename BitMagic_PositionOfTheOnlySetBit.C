#include<stdio.h>
#include<conio.h>


int FindPos(int n){

if(! (n && ! (n & (n-1)))) {
    printf("\nError");
return -1;
}

int pos=1;
int count=0;

while(!(n & pos) ){
pos=pos<<1;
count++;
}

return count+1;
}

int main(){

int n=16;
printf("\nPosition of set bit : %d",FindPos(n));

return 0;
}
