#include<stdio.h>
#include<conio.h>
#include<limits.h>

int FindSum(int freq[],int i,int j){

int k;

int sum=0;

for(k=i;k<=j;k++){
sum+=freq[k];
}


return sum;

}


int FindMinCost_Util(int freq[],int i,int j){


if(i>j){
return 0;
}

if(i==j){
return freq[i];
}


int min=INT_MAX;

int fSum=FindSum(freq,i,j);

int k;
int sum=0;

for(k=i;k<=j;k++){

sum=FindMinCost_Util(freq,i,k-1)+FindMinCost_Util(freq,k+1,j);

if(sum<min){
min=sum;
}

}





return min+fSum;
}

int FindMinCost(int keys[],int freq[],int n){


return FindMinCost_Util(freq,0,n-1);




}


int FindMinCost_DP(int keys[],int freq[],int n){

int dp[n][n];

int i;
int j;

for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(i==j){
dp[i][j]=freq[i];
}
}
}

int k;


int gap;

int min;
for(gap=1;gap<n;gap++){

for(i=0,j=gap;j<n;j++,i++){


dp[i][j]=INT_MAX;

for(k=i;k<=j;k++){
    min=0;
min+=FindSum(freq,i,j);

if(k>i){
min+=dp[i][k-1];
}
if(k<j){
min+=dp[k+1][j];
}


if(min<dp[i][j]){
dp[i][j]=min;
}


}



}

}


for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("%d  ",dp[i][j]);
}
printf("\n");
}

getch();

return dp[0][n-1];
}

int main(){


int keys[]={10,12,20};
//Here keys are sorted but if ther are not sort them and reaarange freq;

int freq[]={34,8,50};

int n=sizeof(keys)/sizeof(keys[0]);

//printf("\nMin cost of BST : %d",FindMinCost(keys,freq,n));
//Min cost is level of an node* freq;



printf("\nMin cost of BST : %d",FindMinCost_DP(keys,freq,n));
return 0;
}
