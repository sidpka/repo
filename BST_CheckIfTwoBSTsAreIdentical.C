#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<limits.h>


int CheckIfIdentical(int a[],int b[],int a_index,int b_index,int n,int min,int max){
int i,j;
for(i=a_index;i<n;i++){
if(a[i]>min && a[i]<max){
break;
}
}

for(j=b_index;j<n;j++){
if(b[j]>min && b[j]<max){
break;
}
}

if(i==n && j==n){
return 1;
}


if(i==n ^ j==n || a[i]!=b[j]){
return 0;
}

return CheckIfIdentical(a,b,i+1,j+1,n,a[i],max) && CheckIfIdentical(a,b,i+1,j+1,n,min,a[i]);

}

int main(){

int a[]={2,1,4,3};
int b[]={2,4,1,3};

int n=sizeof(a)/sizeof(a[0]);

printf("\nPress enter to see if two BSTs are identical :\n\n");
int min=INT_MIN;
int max=INT_MAX;
int result=CheckIfIdentical(a,b,0,0,n,min,max);
if(result){
printf("\nYes identical");
}else{
printf("\nun identical");
}







return 0;
}
