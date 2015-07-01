#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int mid(int s,int e){
return s+(e-s)/2;
}

int ConstructST_Util(int* array,int* ST,int ss,int se,int i){

if(ss==se){
ST[i]=array[ss];
return ST[i];
}

int m=mid(ss,se);

ST[i]=ConstructST_Util(array,ST,ss,m,2*i+1)+
      ConstructST_Util(array,ST,m+1,se,2*i+2);

return ST[i];
}

int* ConstructST(int* array,int n){


int height=(int)ceil(log2(n));
//printf("%d",height);

int size=2*(int)(pow(2,height));

int* ST=(int*)malloc(sizeof(int)*size);

ConstructST_Util(array,ST,0,n-1,0);

return ST;
}

int FindSumUtil(int* ST,int ss,int se,int qs,int qe,int i){

if(qs<=ss  && qe>=se){
return ST[i];
}

if(se<qs || ss>qe){
return 0;
}

int m =mid(ss,se);

return FindSumUtil(ST,ss,m,qs,qe,2*i+1)+
      FindSumUtil(ST,m+1,se,qs,qe,2*i+2);

}


int FindSum(int* ST,int n,int start,int end){

if(start<0 || end>n-1 || start>end){
printf("\nInvalid input");
return -1;
}

return FindSumUtil(ST,0,n-1,start,end,0);


}

void UpdateST_Util(int* ST,int ss,int se,int diff,int index,int i){

if(index< ss || index > se){
return ;
}

ST[i]+=diff;

if(ss!=se){
int m=mid(ss,se);
UpdateST_Util(ST,ss,m,diff,index,2*i+1);
UpdateST_Util(ST,m+1,se,diff,index,2*i+2);
}


}

void UpdateST(int* array,int* ST,int n,int value,int index){

if(index>n-1 || index <0){
printf("\nInvalid \n");
}

int diff=value-array[index];

array[index]=value;
UpdateST_Util(ST,0,n-1,diff,index,0);

}

int main(){

int n;
printf("\nEnter the number of elm : ");
scanf("%d",&n);

printf("\nEnter the elms : \n");
int* array=(int*)malloc(sizeof(int)*n);
int i;

for(i=0;i<n;i++){
scanf("%d",&array[i]);
}

printf("\nPress enter to traverse array : \n\n");
getch();
for(i=0;i<n;i++){
printf("%d  ",array[i]);
}

printf("\nConstruct Segment tree : ");
int* ST=ConstructST(array,n);

printf("\nSee Segment Tree \n");
getch();

for(i=0;i<2*n-1;i++){
printf("%d  ",ST[i]);
}

getch();
int start,end;
printf("\nEnter the range you wan tot find sum : \n");
scanf("%d %d",&start,&end);

int sum=FindSum(ST,n,start,end);
if(sum!=-1){
printf("\nSum is : %d ",sum);
}
getch();
printf("\nEnter the value and index you want to update : ");
int index,value;
scanf("%d %d",&value,&index);
UpdateST(array,ST,n,value,index);
printf("\nTraverse ");
getch();
for(i=0;i<2*n-1;i++){
printf("%d  ",ST[i]);
}
getch();
return 0;
}
