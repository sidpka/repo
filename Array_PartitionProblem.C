#include<stdio.h>
#include<conio.h>

int IsSubset(int* arr,int n,int sum){

if(sum==0){
return 1;
}

if(n==0 && sum!=0){
return 0;
}

if(arr[n-1]>sum){
return IsSubset(arr,n-1,sum);
}

return IsSubset(arr,n-1,sum)|| IsSubset(arr,n-1,sum-arr[n-1]);



}

int FindPartitionI(int* arr,int n){


int sum=0;
int i;
for(i=0;i<n;i++){
sum+=arr[i];
}

if(sum&1){
return 0;
}else{
return IsSubset(arr,n,sum/2);


}

}


int FindPartitionI2(int* arr,int n){

int sum=0;

int i;

for(i=0;i<n;i++){
sum+=arr[i];
}

if(sum%2==1){
return 0;
}

int part[sum/2 +1][n+1];

int j;

for(i=0;i<=n;i++){
part[0][i]=1;
}

for(i=1;i<=sum/2;i++){
part[i][0]=0;
}


for(i=1;i<=sum/2;i++){
for(j=1;j<=n;j++){
part[i][j]=part[i][j-1];

if(i>=arr[j-1]){
part[i][j]=part[i][j] || part[i-arr[j-1]][j-1];
}

}
}

for(i=0;i<=sum/2;i++){

for(j=0;j<=n;j++){
printf("%d  ",part[i][j]);

}

printf("\n");

}

return part[sum/2][n];

}


int main(){


int arr[]={1,5,11,5};

int n=sizeof(arr)/sizeof(arr[0]);

//int result=FindPartitionI(arr,n);


int result=FindPartitionI2(arr,n);


if(result){
printf("\nYes");
}else{
printf("\nNo");
}





return 0;
}
