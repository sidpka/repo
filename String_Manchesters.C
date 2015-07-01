#include<stdio.h>
#include<conio.h>
#include<string.h>


void FindManchester(char str[]){

int N=strlen(str);
if(N==0){
return;
}
N=2*N+1;
int LPS[N];
LPS[0]=0;
LPS[1]=1;

int maxLen=0;
int MaxLenCenter=0;

int C=1;
int R=2;
int i; //currentRight
int iMirror; // currentLeft;

int expand;
int diff;

for(i=2;i<N;i++){
expand=0;

diff=R-i;
iMirror=2*C-i;

if(diff>0){

if(LPS[iMirror]<diff){
LPS[i]=LPS[iMirror];
}else if(LPS[iMirror]==diff && R==N-1){
LPS[i]=LPS[iMirror];
}else if(LPS[iMirror]==diff && R<N-1){
LPS[i]=LPS[iMirror];
expand=1;
}else if(LPS[iMirror]>diff){
LPS[i]=diff;
expand=1;
}


}else{
LPS[i]=0;
expand=1;
}

if(expand==1){

while( (i+LPS[i]<N) && (i-LPS[i] >0) && ( (i+LPS[i]+1)%2==0 ||  (str[ (i +LPS[i]+1 )/2  ] == str[  (i-LPS[i]-1)/2  ])  ) ){
LPS[i]++;
}

}

if(LPS[i]>maxLen){
maxLen=LPS[i];
MaxLenCenter=i;
}

if(i+LPS[i]>R){
R=i+LPS[i];
C=i;
}


}

int start=(MaxLenCenter-maxLen)/2;
int end=start+maxLen-1;
printf("\nMax len palindroem : %d\nAnd palindorme is : \n",maxLen);
for(i=start;i<=end;i++){
printf("%c",str[i]);
}



}

int min(int a,int b){

return a<b?a:b;
}

void FindManchester2(char str[]){

int N=strlen(str);

N=2*N+1;

int LPS[N];
LPS[0]=0;
LPS[1]=1;

int maxLen=0;
int maxLenCenter=0;

int C=1;
int R=2;

int iMirror;

int i;

int diff;

for(i=2;i<N;i++){
iMirror=2*C-i;
LPS[i]=0;


diff=R-i;

if(diff>0){
LPS[i]=min(LPS[iMirror],diff);
}

while( (i+LPS[i]<N) && (i-LPS[i]>0) && ( (i+LPS[i]+1)%2==0 || (str[ (i+LPS[i]+1)/2   ]==str[ (i-LPS[i]-2)/2  ])    )   ){
LPS[i]++;
}

if(LPS[i]>maxLen){
maxLen=LPS[i];
maxLenCenter=i;
}

if(i+LPS[i]>R){

    C=i;
    R=i+LPS[i];

}

}

int start=(maxLenCenter-maxLen)/2;
int end=start+maxLen-1;
printf("\nLongest Palindromic Substring : %d\nAnd LPS is :  ",maxLen);
for(i=start;i<=end;i++){
printf("%c",str[i]);
}



}

int main(){


char str[]="babcbabcbaccba";

//FindManchester(str);

FindManchester2(str);


return 0;
}
