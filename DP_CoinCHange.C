#include<stdio.h>
#include<conio.h>


int FindChange(int S[],int m,int n){


if(n==0){
return 1;
}

if(n<0){
return 0;
}

if(m<=0 && n>0){
return 0;
}

return FindChange(S,m-1,n)+FindChange(S,m,n-S[m-1]);





}

int FindChange_DP(int S[],int m,int n){

int dp[n+1][m+1];

int i;
int j;

for(i=0;i<=n;i++){

for(j=0;j<=m;j++){

if(i==0){
dp[i][j]=1;
}else if(j==0){
dp[i][j]=0;
}else{

dp[i][j]=dp[i][j-1];

if(S[j-1]<=i){
dp[i][j]+=dp[i-S[j-1]][j];
}


}

}

}

for(i=0;i<=n;i++){
for(j=0;j<=m;j++){

printf("%d  ",dp[i][j]);

}
printf("\n");
}


return dp[n][m];
}


int FindChange_DP2(int S[],int m,int n){

int dp[n+1];



int i;
int j;

for(i=1;i<=n;i++){
dp[i]=0;
}

dp[0]=1;

for(i=0;i<m;i++){

for(j=S[i];j<=n;j++){

dp[j]+=dp[j-S[i]];

}

}

/*
for(i=0;i<=n;i++){
printf("%d  ",dp[i]);
}

getch();
*/

return dp[n];


}

int main(){

int S[]={1,2,3};

int m=sizeof(S)/sizeof(S[0]);

int n=4;

//printf("\nNo of ways to get change of %d are : %d",n,FindChange(S,m,n));

//printf("\nNo of ways to get change of %d are : %d",n,FindChange_DP(S,m,n));

printf("\nNo of ways to get change of %d are : %d",n,FindChange_DP2(S,m,n));

return 0;
}
