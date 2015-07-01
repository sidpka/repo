#include<stdio.h>
#include<conio.h>
#include<string.h>

int FindLCS(char X[],char Y[]){

int lenX=strlen(X);
int lenY=strlen(Y);

int i;
int j;
int k;

int m=0;

int maxLen=0;

for(i=0;i<lenX;i++){

for(j=0;j<lenY;j++){

m=i;

for(k=j;k<lenY && m<lenX;k++){
if(X[m]==Y[k]){
m++;
}else{
break;
}
}
if(maxLen<(m-i)){
maxLen=m-i;
}
}

}


return maxLen;
}

int FindLCS_DP(char X[],char Y[]){

int lenX=strlen(X);
int lenY=strlen(Y);

int dp[lenX][lenY];

int i;
int j;

for(i=0;i<lenX;i++){

for(j=0;j<lenY;j++){
dp[i][j]=0;
}

}


int maxLen=0;

for(i=0;i<lenX;i++){

for(j=0;j<lenY;j++){

if(X[i]==Y[j] && i>0 && j>0){
dp[i][j]=dp[i-1][j-1]+1;
if(maxLen<dp[i][j]){
maxLen=dp[i][j];
}
}else if(X[i]==Y[j]){
dp[i][j]=1;
}



}


}





return maxLen;

}

int main(){

//char X[]="GeeksForGeeks";
//char Y[]="GeeksQuiz";

//char X[]="busid";
//char Y[]="pansidpandey";

 char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";




//printf("\nLongestCommonSubstring is of length : %d",FindLCS(X,Y));

printf("\nLongestCommonSubstring is of length : %d",FindLCS_DP(X,Y));




return 0;
}
