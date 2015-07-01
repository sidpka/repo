#include<stdio.h>
#include<conio.h>

void FindPascal(int n){

int i;
int j;
int k;

int res=1;

for(i=0;i<=n;i++){

for(j=0;j<=i;j++){
res=1;

for(k=0;k<j;k++){
res*=(i-k);
res/=(k+1);
}
printf("%d  ",res);


}
printf("\n");

}

}


int FindPascal2(int n){

int dp[n+1][n+1];

int i;

for(i=0;i<=n;i++){
dp[i][0]=1;
dp[i][i]=1;
}

int j;

for(i=1;i<=n;i++){

for(j=1;j<i;j++){
dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
}

}


printf("\nPascal Trianlge\n\n");

for(i=0;i<=n;i++){
for(j=0;j<=i;j++){
printf("%d  ",dp[i][j]);
}
printf("\n");
}


}



void FindPascal3(int n){

int line;
int i;
int C;
for(line=1;line<=n;line++){
C=1;

for(i=1;i<=line;i++){
printf("%d  ",C);
C=C*(line-i)/i;
}
printf("\n");
}


}


int main(){

int n=5;

//FindPascal(n);

//FindPascal2(n);

FindPascal3(n);


return 0;
}
