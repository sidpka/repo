#include<stdio.h>
#include<conio.h>
#include<limits.h>

#define row 4
#define col 5



int Kadane(int* arr,int* start,int* finish){


int i;

int localStart=0;
int flag=0;
int sum=0;
int maxSum=INT_MIN;
for(i=0;i<row;i++){
sum+=arr[i];
if(sum<0){
sum=0;
localStart=i+1;
}else if(sum>maxSum){
maxSum=sum;
*start=localStart;
*finish=i;
flag=1;
}

}

if(flag==1){
return maxSum;
}

maxSum=arr[0];
*start=0;
*finish=0;
for(i=1;i<row;i++){

if(arr[i]>maxSum){
maxSum=arr[i];
*start=i;
*finish=i;
}

}

return maxSum;

}



void MaxSumRectangle(int mat[row][col]){



int left;
int right;

int start;
int finish;

int finalLeft;
int finalRight;

int finalTop;
int finalBottom;


int i;

int sum;
int maxSum=INT_MIN;

for(left=0;left<col;left++){

int tmp[row]={0};

for(right=left;right<col;right++){

for(i=0;i<row;i++){
tmp[i]+=mat[i][right];
}

sum=Kadane(tmp,&start,&finish);
//printf("\nSUM : %d\n",sum);
if(sum>maxSum){

maxSum=sum;
finalLeft=left;
finalRight=right;
finalTop=start;
finalBottom=finish;

}

}







}







printf("\nMax sum : %d",maxSum);

printf("\nLeft,Top : (%d,%d)",finalLeft,finalTop);
printf("\nRight,Top : (%d,%d)",finalRight,finalTop);
printf("\nLeft,Bottom : (%d,%d)",finalLeft,finalBottom);
printf("\nRight,Bottom : (%d,%d)",finalRight,finalBottom);


}

int main(){

int mat[row][col]={ {1,2,-1,-4,-20},{-8,-3,4,2,1},{3,8,10,1,3},{-4,-1,1,7,-6}};

MaxSumRectangle(mat);



return 0;
}
