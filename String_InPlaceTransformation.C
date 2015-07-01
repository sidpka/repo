#include<stdio.h>
#include<conio.h>

#include<string.h>
#include<math.h>



void Swap(char* a,char* b){

char tmp=*a;
*a=*b;
*b=tmp;


}

void CycleLeader(char str[],int shift,int len){

int i;
int j;
char item;
for(i=1;i<len;i*=3){

j=i;

item=str[j+shift];

do{

if(j&1){

j=len/2 + j/2;

}else{
j=j/2;
}

Swap(&str[j+shift],&item);


}while(i!=j);



}



}


void Reverse(char str[],int low,int high){

while(low<high){
Swap(&str[low],&str[high]);
low++;
high--;

}


}

void FindX(char str[]){


int n=strlen(str);

int i;

int curLen;
int rLen=n;

int k;
int shift=0;
while(rLen){
k=0;
while(pow(3,k)+1<=rLen){
k++;
}

curLen=pow(3,k-1)+1;

rLen-=curLen;

CycleLeader(str,shift,curLen);


Reverse(str,shift/2,shift-1);
Reverse(str,shift,shift+curLen/2-1);
Reverse(str,shift/2,shift+curLen/2-1);

shift+=curLen;




}



}

int main(){

char str[]="a1b2c3d4e5f6g7";
FindX(str);

//CycleLeader(str,10);
printf("\n%s",str);





return 0;
}
