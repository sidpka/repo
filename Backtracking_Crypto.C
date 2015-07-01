#include<stdio.h>
#include<conio.h>
#include<string.h>

int IsSafe(int buffer[],char ch,int i){

if(buffer[i]!=0){
return 0;
}

int j;

for(j=0;j<10;j++){
if(buffer[j]==ch){
return 0;
}
}


return 1;


}

int max(int a,int b){
return a>b?a:b;
}

int FindSum(char first[],int m,char second[],int n,char sum[],int p){

int carry=0;

int i;

//for(i=0;i<)
return 1;

}

int FindCrypto_Util(char first[],int sm,int m,char second[],int sn,int n,char sum[],int sp,int p,int buffer[],int index){

if(sm==m && sn==n && sp==p){

if(FindSum(first,m,second,n,sum,p)){
return 1;
}else{
return 0;
}

}

int i;

if(sm<m){

for(i=0;i<10;i++){
if(IsSafe(buffer,first[sm],i)){
buffer[i]=first[sm];
if(FindCrypto_Util(first,sm+1,m,second,sn,n,sum,sp,p,buffer,index)){
return 1;
}else{
buffer[i]=0;
}
}
}

}


if(sn<n){

for(i=0;i<10;i++){
if(IsSafe(buffer,second[sn],i)){
buffer[i]=second[sn];
if( FindCrypto_Util(first,sm,m,second,sn+1,n,sum,sp,p,buffer,index) ){
return 1;
}else{
buffer[i]=0;
}
}
}

}

if(sp<p){

for(i=0;i<10;i++){
if(IsSafe(buffer,sum[sp],i)){
buffer[i]=sum[sp];
if( FindCrypto_Util(first,sm,m,second,sn,n,sum,sp+1,p,buffer,index) ){
return 1;
}else{
buffer[i]=0;
}
}
}

}

return 0;

}

void FindCrypto(char first[],int m,char second[],int n,char sum[],int p,int buffer[],int  index){

if(FindCrypto_Util(first,0,m,second,0,n,sum,0,p,buffer,0)){
int i;

for(i=0;i<10;i++){
printf("%c\t%d",buffer[i],i);
}
}else{
printf("\nSolution doesn't exist");
}



}

int main(){

char first[]="SEND";
char second[]="MORE";

char sum[]="MONEY";

int buffer[10];

int i;

for(i=0;i<10;i++){
buffer[i]=0;
}

FindCrypto(first,strlen(first),second,strlen(second),sum,strlen(sum),buffer,0);





return 0;
}
