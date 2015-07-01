#include<stdio.h>
#include<conio.h>
#include<string.h>

int FindInterleaving(char* A,char* B,char* C){

while(*C!=0){

if(*A==*C){
A++;
C++;
}

else if(*B==*C){
B++;
C++;
}else{
return 0;
}

}

if(*A || *B){
return 0;
}

return 1;



}

int FindInterleaving2(char* A,char* B,char* C){


if(!(*A || *B || *C)){
return 1;
}

if(*C=='\0'){
return 0;
}

return ((*A==*C)&& FindInterleaving2(A+1,B,C+1) ||
        (*B==*C)&& FindInterleaving2(A,B+1,C+1));




}


int FindInterleaving_DP(char* A,char* B,char* C){

int m=strlen(A);
int n=strlen(B);

int dp[m+1][n+1];

int i;

int j;
if(m+n!=strlen(C)){
return 0;
}
for(i=0;i<m;i++){

for(j=0;j<n;j++){

if(i==0 && j==0){
dp[i][j]=1;
}

else if(i==0 && B[j-1]==C[j-1]){
dp[i][j]=dp[i][j-1];
}

else if(j==0 && A[i-1]==C[i-1]){
dp[i][j]=dp[i-1][j];
}


else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1]){
dp[i][j]=dp[i-1][j];
}

else if(B[j-1]==C[i+j-1] && A[i-1]!=C[i+j-1]){
dp[i][j]=dp[i][j-1];
}


else if(A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1]){
dp[i][j]=(dp[i-1][j] || dp[i][j-1]);
}

}


}




return dp[m][n];
}


int main(){


char A[]="AB";
char B[]="AD";

char C[]="AABD";

//int result=FindInterleaving(A,B,C);
//int result=FindInterleaving2(A,B,C);
int result=FindInterleaving_DP(A,B,C);
if(result){
printf("\n%s is interleaved of %s and %s",C,A,B);
}else{
printf("\n%s is not interleaved of %s and %s",C,A,B);
}


return 0;
}
