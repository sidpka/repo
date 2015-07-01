#include<stdio.h>
#include<conio.h>
#include<string.h>
#define row 4
#define col 3


int FindDigits_Util(char Numeric[row][col],int i,int j,int n){

if(n<=0){
return 0;
}

if(n==1){
return 1;
}

int r[]={0,0,-1,0,1};
int c[]={0,-1,0,1,0};

int k;
int total=0;
for(k=0;k<5;k++){

int ro=i+r[k];
int co=j+c[k];

if( ro>=0 && ro<=3 && co>=0 && co<=2 && Numeric[ro][co]!='*' && Numeric[ro][co]!='#'){
total+=FindDigits_Util(Numeric,ro,co,n-1);
}

}



return total;



}



int FindDigits(char Numeric[row][col],int n){

int total;
if(n==0){
return 0;
}

if(n==1){
return 10;
}

int i;
int j;
total=0;
for(i=0;i<row;i++){
for(j=0;j<col;j++){
    if(Numeric[i][j]!='*' && Numeric[i][j]!='#'){
total+=FindDigits_Util(Numeric,i,j,n);
    }
}
}

return total;

}


int FindDigits2(char Numeric[row][col],int n){

int i;
int j;

int r[]={0,0,-1,0,1};
int c[]={0,-1,0,1,0};

int count[10][n+1];

for(i=0;i<10;i++){
count[i][0]=0;
count[i][1]=1;
}

int k;
int l;
for(k=2;k<=n;k++){


for(i=0;i<row;i++){
for(j=0;j<col;j++){

if(Numeric[i][j]!='*' && Numeric[i][j]!='#'){
int index=Numeric[i][j]-'0';
count[index][k]=0;

for(l=0;l<5;l++){
int ro=i+r[l];
int co=j+c[l];

if(ro>=0 && ro<row && co>=0 && co<col && Numeric[ro][co]!='*' && Numeric[ro][co]!='#'){
int nextIndex=Numeric[ro][co]-'0';
count[index][k]+=count[nextIndex][k-1];
}

}
}

}

}




}

int total=0;

for(i=0;i<10;i++){
total+=count[i][n];
}


return total;


}


int main(){

char Numeric[row][col]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'} };
int n=3;

//printf("\nNumber of numbers formed when number of digits used : %d :is  %d",n,FindDigits(Numeric,n));


//DP
printf("\nNumber of numbers formed when number of digits used : %d :is  %d",n,FindDigits2(Numeric,n));


return 0;
}
