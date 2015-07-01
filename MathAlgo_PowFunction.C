#include<stdio.h>
#include<conio.h>


int FindPow(int base,int pow){




int sum=base;

int i;
int j;

int currentSum;
if(pow==0){
return 1;
}
for(i=1;i<pow;i++){
currentSum=sum;
for(j=1;j<base;j++){
sum+=currentSum;
}
}

return sum;
}


int FindPow_Util(int base,int pow,int it){

if(it==0){
pow=pow-1;

}

}


int FindPow2(int base,int pow){



if(pow==0){
return 1;
}

return FindPow_Util(base,pow,base);



}


int main(){

int base=3;
int power=5;

//printf("\n%d ^ %d : %d",base,power,FindPow(base,power));

printf("\n%d ^ %d   : %d",base,power,FindPow2(base,power));



return 0;
}
