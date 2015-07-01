#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>


int GetMid(int s,int e){

return s+(e-s)/2;

}

int min(int a,int b){
return a<b?a:b;
}

int ConstructSegementTree_Util(int* array,int* ST,int ss,int se,int i){

if(ss==se){
ST[i]=array[ss];
return ST[i];
}

int mid=GetMid(ss,se);

ST[i]= min(ConstructSegementTree_Util(array,ST,ss,mid,2*i+1),
      ConstructSegementTree_Util(array,ST,mid+1,se,2*i+2));



return ST[i];




}

int* ConstructSegementTree(int* array,int n){


int h=(int)(ceil(log2(n)));


int size=2*(int)(pow(2,h))-1;

int* segementTree=(int*)malloc(sizeof(int)*size);

ConstructSegementTree_Util(array,segementTree,0,n-1,0);

return segementTree;
}
/*
int FindSum_Util(int* ST,int ss,int se,int qs,int qe,int i){

if(qs<=ss && qe>=se){
return ST[i];
}

if(qs>se || qe<ss){
return 0;
}


int mid=GetMid(ss,se);

return FindSum_Util(ST,ss,mid,qs,se,2*i+1)+
    FindSum_Util(ST,mid+1,se,qs,qe,2*i+2);


}


int FindSum(int* ST,int n,int qs,int qe){

if(qs>n-1 ||  qe<0 || qs>qe){
    printf("\nInvalid \n");
return -1;
}

return FindSum_Util(ST,0,n-1,qs,qe,0);
}

void UpdateST_Util(int* ST,int ss,int se,int diff,int index,int i){

if(index<ss || index>se){
return ;
}

ST[i]+=diff;

if(ss!=se){
int mid=GetMid(ss,se);
UpdateST_Util(ST,ss,mid,diff,index,2*i+1);
UpdateST_Util(ST,mid+1,se,diff,index,2*index+2);
}

}


void UpdateST(int* array,int* ST,int n,int value,int index){

if(index<0 || index>n-1){

return;
}

int diff=value-array[index];
array[index]=value;

UpdateST_Util(ST,0,n-1,diff,index,0);

}

int RangeMinQuery_Util(int* ST,int ss ,int se,int qs,int qe,int i){




}

*/

int RangeMinQuery_Util(int* ST,int ss,int se,int qs,int qe,int i){
if(qs<=ss && qe>=se){
return ST[i];
}

if(qs>se || qe<ss){
return INT_MAX;
}

int mid=GetMid(ss,se);

return min(RangeMinQuery_Util(ST,ss,mid,qs,qe,2*i+1),RangeMinQuery_Util(ST,mid+1,se,qs,qe,2*i+2));


}

int RangeMinQuery(int* ST,int n,int start,int end){

if(start>n-1 || end<0){
printf("\nInvalid");
return -1;
}


return RangeMinQuery_Util(ST,0,n-1,start,end,0);
}

int main(){

int n;
printf("\nEnter the number of elements in the array : ");
scanf("%d",&n);
int* array=(int*)malloc(sizeof(int)*n);

int i;

printf("\nEnter the elements of the array : ");

for(i=0;i<n;i++){
    scanf("%d",&array[i]);
}

int* segementTree=ConstructSegementTree(array,n);

printf("\nSegment Tree :\n");

for(i=0;i<2*n-1;i++){
printf("%d ",segementTree[i]);
}


/*
printf("\nEnter range to find sum : ");
int f,s;
scanf("%d %d",&f,&s);
int sum=FindSum(segementTree,n,f,s);
if(sum!=-1){
printf("\nSum is : %d",sum);
}

printf("\nEnter value and index you want to update : ");
scanf("%d %d",&f,&s);

UpdateST(array,segementTree,n,f,s);
*/


getch();

int start,end;

printf("\nEnter the range to find minimum : ");
scanf("%d %d",&start,&end);

int minValue=RangeMinQuery(segementTree,n,start,end);
if(minValue!=-1){
printf("\nMinimum in range [%d--%d] is : %d",start,end,minValue);
}


return 0;
}
