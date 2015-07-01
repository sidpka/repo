#include<stdio.h>
#include<conio.h>


int FindGcd(int a,int b){

if(a%b==0){
return b;
}

return FindGcd(b,a%b);


}

void Find1Litre(int V1,int V2){

int gcd=FindGcd(V2,V1);
//printf("\ngcd : %d",gcd);

if(gcd!=1){
printf("\nCant be found \n");
return;
}

int a=V1;
int b=V2;
V1=0;
V2=0;
while(V1!=1){
printf("\nV1 : %d \t V2: %d",V1,V2);

if(V1==0){
V1=a;
}

if(V2==0){
V2=V1;
V1=0;
}
else if(V2!=b){
int diff=b-V2;
if(diff>=V1){
V2+=V1;
V1=0;
}else{
V1-=diff;
V2=b;
}
}

if(V2==b && V1!=1){
V2=0;
}

}


}

int main(){

int V1=1;
int V2=2;

Find1Litre(V1,V2);





return 0;
}
