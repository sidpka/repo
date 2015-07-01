#include<stdio.h>
#include<conio.h>
#define rows 4
#define cols 3

int IsInRange(char keypad[rows][cols], int i,int j,int k){
int row[]={0,0,0,-1,1};
int col[]={0,-1,1,0,0};

int ro=i+row[k];
int co=j+col[k];

if((ro>=0 && ro<rows) && (co>=0 && co<cols) && (keypad[ro][co]!='*' && keypad[ro][co]!='#')){
return 1;
}
return 0;

}


int FindCount_Util(char keypad[rows][cols],int ro,int co,int N){


if(N==0){
return 1;
}

int row[]={0,0,0,-1,1};
int col[]={0,-1,1,0,0};

int m=sizeof(row)/sizeof(row[0]);

int i;
int j;
int count=0;

for(i=0;i<m;i++){
if(IsInRange(keypad,ro,co,i) ){
count+=FindCount_Util(keypad,ro+row[i],co+col[i],N-1);
}
}

return count;
}


int FindCount(char keypad[rows][cols],int N){
if(N==0){
return 0;
}

int count=0;
int i;
int j;
int k;

int row[]={0,0,0,-1,1};
int col[]={0,-1,1,0,0};

int m=sizeof(row)/sizeof(row[0]);

for(i=0;i<rows;i++){

for(j=0;j<cols;j++){

if(keypad[i][j]!='*' && keypad[i][j]!='#'){

//for(k=0;k<m;k++){

//if(IsInRange(keypad,i,j,k)){
    //printf("\nHere");
//count+=FindCount_Util(keypad,i+row[k],j+col[k],N-1);
count+=FindCount_Util(keypad,i,j,N-1);
}

//}
//}
}
}

return count;
}


int FindIndex(int i,int j){

if(i<rows-1){
return i*cols+j+1;
}

return 0;
}

int FindCount_DP(char keypad[rows][cols],int N){

if(N==0){
return 0;
}

int dp[10][N+1];

int i;
int j;

for(i=0;i<10;i++){
for(j=0;j<=N;j++){
dp[i][j]=0;
}
}


for(i=0;i<10;i++){
dp[i][1]=1;
}


int row[]={0,0,0,-1,1};
int col[]={0,-1,1,0,0};

int n=sizeof(row)/sizeof(row[0]);
int k;
for(k=2;k<=N;k++){
for(i=0;i<rows;i++){
for(j=0;j<cols;j++){

if(keypad[i][j]!='*' && keypad[i][j]!='#'){
int m;
int index=FindIndex(i,j);
for(m=0;m<n;m++){
if(IsInRange(keypad,i,j,m)){
dp[index][k]+=dp[FindIndex(i+row[m],j+col[m])][k-1];
}
}

}


}

}
}

int count=0;

for(i=0;i<10;i++){
count+=dp[i][N];
}
return count;
}

int main(){


char keypad[rows][cols]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'} };

int N=2;
//printf("\nNo of numbers of length : %d will bcm: %d",N,FindCount(keypad,N));

printf("\nNo of numbers of length : %d will bcm : %d",N,FindCount_DP(keypad,N));


return 0;
}
