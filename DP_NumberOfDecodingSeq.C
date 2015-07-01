#include<stdio.h>
#include<conio.h>
#include<string.h>


int FindDecodingSeq(char str[],int src,int dest){
int n=dest-src+1;
if(n==0){
return 0;
}

if(n==1){
return 1;
}

if(n==2){
return 2;
}

int count=0;

int i;

count+=FindDecodingSeq(str,src+1,dest)+FindDecodingSeq(str,src+2,dest);

return count;






}

int FindDecodingSeq2(char str[],int n){

int count[n+1];
count[0]=1;
count[1]=1;

int i;

for(i=2;i<=n;i++){
count[i]=0;
if(str[i-1]>'0'){
count[i]+=count[i-1];
}

if( (str[i-2]<'2' || str[i-2]=='2' ) && str[i-1]<'7' ){
count[i]+=count[i-2];
}

}


return count[n];
}

int main(){


char str[]="123";

int n=strlen(str);

//printf("\nNo of decoding sequences possible : %d",FindDecodingSeq(str,0,n-1));

printf("\nNo of decoding sequences possible : %d",FindDecodingSeq2(str,n));






return 0;
}
