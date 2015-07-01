#include<stdio.h>
#include<conio.h>

int FindIfLuckyNumber(int position,int deleteAtPosition){

if(position<deleteAtPosition){
return 1;
}

if(position%deleteAtPosition==0){
return 0;
}

position-=position/deleteAtPosition;

return FindIfLuckyNumber(position,deleteAtPosition+1);


}

int FindIfLuckyNumber2(int num){

int deleteAtPosition=2;

while(1){

if(num<deleteAtPosition){
return 1;
}

if(num%deleteAtPosition==0){
return 0;
}

num-=num/deleteAtPosition;
deleteAtPosition+=1;
}

}

int main(){


int num=19;


//int result=FindIfLuckyNumber(num,2);
int result=FindIfLuckyNumber2(num);
result?printf("\nYes"):printf("\No");



return 0;
}
