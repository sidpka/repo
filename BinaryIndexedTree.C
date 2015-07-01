#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void ConstructBIT(int* BITree,int data,int index,int n){
index=index+1;
while(index<=n){
BITree[index]+=data;
index+=(index)&(-index);
}
}

int FindSum_Util(int* BITree,int index){

index=index+1;

int sum=0;

while(index>0){
sum+=BITree[index];
index-=index&(-index);
}
return sum;
}

int FindSum(int* BITree,int start,int end,int n){

if(start>n || end<0 || start>end){
return 0;
}

int result=FindSum_Util(BITree,end)-FindSum_Util(BITree,start-1);

return result;

}

void UpdateBIT(int* BITree,int diff,int index,int n){
index=index+1;
while(index<=n){
BITree[index]+=diff;
index+=(index)&(-index);
}



}


int main(){


printf("\nEnter length of array : ");
int n;
scanf("%d",&n);

int* array=(int*)malloc(sizeof(int)*n);

int i;
printf("\nEnter the element of the array : ");
for(i=0;i<n;i++){
scanf("%d",&array[i]);
}

int* BITree=(int*)malloc(sizeof(int)*(n+1));

for(i=0;i<=n;i++){

BITree[i]=0;

}

for(i=0;i<n;i++){
ConstructBIT(BITree,array[i],i,n);
}

printf("\nInitial BTree\n");

for(i=0;i<=n;i++){
printf("%d  ",BITree[i]);
}

int start,end;

printf("\nEnter a range to find sum : ");
scanf("%d %d",&start,&end);

int result=FindSum(BITree,start,end,n);
printf("\nRange sum is : %d",result);
getch();

int index,value;
printf("\nEnter index and new value : ");
scanf("%d %d",&index,&value);

int diff=value-array[index];

/*
printf("\n");
for(i=0;i<=n;i++){
printf("%d  ",BITree[i]);
}

printf("\nDiff is : %d",diff);
printf("\n");
for(i=0;i<=n;i++){
printf("%d  ",BITree[i]);
}


getch();
*/

UpdateBIT(BITree,diff,index,n);
printf("\nEnter a range to find sum : ");
scanf("%d %d",&start,&end);

result=FindSum(BITree,start,end,n);
printf("\nRange sum is : %d",result);
getch();
return 0;
}
