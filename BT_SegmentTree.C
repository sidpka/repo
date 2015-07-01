#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>


int GetMid(int left,int right){
return left+(right-left)/2;
}

int CreateST(int* ST,int* arr,int left,int right,int index){

if(left==right){
ST[index]=arr[left];
return arr[left];
}
int mid=GetMid(left,right);
ST[index]=CreateST(ST,arr,left,mid,2*index+1)+CreateST(ST,arr,mid+1,right,2*index+2);
return ST[index];
}

int GetSumUtility(int* ST,int left,int right,int qLeft,int qRight,int index){

if(qLeft<=left && qRight>=right){
return ST[index];
}

if(qLeft>right || qRight<left){
return 0;
}

int mid=GetMid(left,right);

return GetSumUtility(ST,left,mid,qLeft,qRight,2*index+1)+GetSumUtility(ST,mid+1,right,qLeft,qRight,2*index+2);

}

int GetSum(int* ST,int left,int right,int n){
if(left>right || left<0 || right>=n){
return 0;
}
return GetSumUtility(ST,0,n-1,left,right,0);
}

void UpdateSTUtility(int* ST,int left,int right,int i,int diff,int index){
if(i<left || i> right){
return;
}
ST[index]+=diff;
if(left!=right){
    int mid=GetMid(left,right);
UpdateSTUtility(ST,left,mid,i,diff,2*index+1);
UpdateSTUtility(ST,mid+1,right,i,diff,2*index+2);
}
}

void UpdateST(int*ST,int*arr,int value,int index,int n){
if(index<0 || index >=n){
printf("\nInvalid index");
return;
}
int diff=value-arr[index];
arr[index]=value;
UpdateSTUtility(ST,0,n-1,index,diff,0);

}
int main(){

int arr[]={1,3,5,7,9,11};
int n=sizeof(arr)/sizeof(arr[0]);
int height=ceil(log2(n));
int sizeST=2*(int)pow(2,height);
int* ST=(int*)malloc(sizeof(int)*sizeST);
CreateST(ST,arr,0,n-1,0);
int i;
int value,index;
printf("\nEnter the value u want to update and of index : ");
scanf("%d %d",&value,&index);
UpdateST(ST,arr,value,index,n);
printf("\nEnter the sum between range : enter range : \n");
int l,r;
scanf("%d %d",&l,&r);
printf("\nAnswer : %d\n\n",GetSum(ST,l,r,n));


//testing
for(i=0;i<16;i++){
printf("%d  ",ST[i]);
}
//end testing
return 0;
}
