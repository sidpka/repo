#include<stdio.h>
#include<conio.h>

void CheckEndian(char* arr,int n){


int i;

for(i=0;i<n;i++){
printf("%.2x",arr[i]);
}


}

int CheckEndian2(){
int n=1;
char* c=&n;

if(*c){
return 1;//little endian
}else{
return 0;//big endian
}


}

int main(){

//int num=0x01234567;

//CheckEndian((char*)&num,sizeof(num));

int result=CheckEndian2();
result==1?printf("\nLittle Endian"):printf("\nBig Endian")

return 0;
}
