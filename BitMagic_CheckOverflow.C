#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

int CheckIfOverflow(int a,int b,int* result){

*result=a+b;

if(a>0 && b>0 && *result<0){
    printf("\nHere");
return 1;
}

if(a<0 && b<0 && *result>0){
return 1;
}


return  0;
}

int CheckIfOverflow2(int a,int b,int* result){

if(a>INT_MAX-b){
return 1;
}else{
*result=a+b;
return 0;
}


}

int main(){

int a=2147483640;
int b=10;

int* result=(int*)malloc(sizeof(int));
int flag=CheckIfOverflow2(a,b,result);
//int flag=CheckIfOverflow(a,b,result);

if(flag){
printf("\nOverflow");
}else{
printf("\nSum : %d",*result);
}

return 0;
}
