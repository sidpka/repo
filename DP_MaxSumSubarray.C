#include<stdio.h>
#include<conio.h>

#include<limits.h>

#define rows 4
#define cols 5


int Kadane(int dp[],int* start,int* end){


int localStart;

int sum=0;
int maxSum=INT_MIN;
(*end)=-1;
int i;

for(i=0;i<rows;i++){


sum+=dp[i];

if(sum<0){
localStart=i+1;
sum=0;
}

if(sum>maxSum){
(*start)=localStart;
(*end)=i;
maxSum=sum;
}




}

if(*end!=-1){
return maxSum;
}


(*start)=(*end)=0;

maxSum=dp[0];

for(i=1;i<rows;i++){
if(maxSum<dp[i]){
maxSum=dp[i];
(*start)=i;
(*end)=i;
}

}

return maxSum;





}


void FindMaxSumSubarray(int arr[rows][cols]){

int left;
int i;
int right;
int sum=0;
int finalLeft;
int finalRight;
int finalTop;
int finalBottom;

int start;
int end;
int maxSum=INT_MIN;

for(left=0;left<cols;left++){

int dp[rows]={0};
for(right=left;right<cols;right++){


for(i=0;i<rows;i++){
dp[i]+=arr[i][right];
}

sum=Kadane(dp,&start,&end);


if(sum>maxSum){
maxSum=sum;
finalBottom=end;
finalTop=start;
finalLeft=left;
finalRight=right;



}




}




}



printf("\nMaxSum : %d\n",maxSum);
printf("\nMaxSum Subarray \n");
printf("\n[%d]\t[%d]\n[%d]\t[%d]",finalTop,finalRight,finalLeft,finalBottom);



}


int main(){


int arr[rows][cols]={{1,2,-1,-4,-20},{-8,-3,4,2,1},{3,8,10,1,3},{-4,-1,1,7,-6}};

FindMaxSumSubarray(arr);

return 0;
}
