#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct xx{
char str[1000];
};

typedef struct xx x;

int cmp(char* X,char* Y){

//char* XY=strcat(X,Y);

//char* YX=strcat(Y,X);
int len=sizeof(X)+sizeof(Y);
char* xy=(char*)malloc(sizeof(char)*len);
//printf("\nlen is : %d",len);
//strcpy(xy,)xy='\0';
xy[0]='\0';
xy=strcpy(xy,X);
xy=strcat(xy,Y);
//printf("\nIn cmp");
char* yx=(char*)malloc(sizeof(char)*len);
//yx='\0';
yx[0]='\0';

yx=strcat(yx,Y);
yx=strcat(yx,X);

//printf("\nCompared : %s and %s\n",xy,yx);
return strcmp(xy,yx)>0?1:0;
}

void Swap(x arr[],int left ,int right){
char* tmp=(char*)malloc(sizeof(char)*sizeof(arr[left].str));
strcpy(tmp,arr[left].str);
strcpy(arr[left].str,arr[right].str);
strcpy(arr[right].str,tmp);
free(tmp);
}


int Partition(x arr[],int low,int high){
char* pivotElm=(char*)malloc(sizeof(char)*sizeof(arr[low].str));
strcpy(pivotElm,arr[low].str);
//printf("\nPivot Elm is : %s",pivotElm);
int left=low;
int right=high;

//int tmp=cmp(pivotElm,arr[left].str);
//printf("\nIn partition : %d",tmp);

while(left<right){
while(cmp(pivotElm,arr[left].str)){
left++;
}

while(cmp(arr[right].str,pivotElm )){
   // printf("\nlow : %d high : %d",low,high);
right--;
}

if(left<right){
    //printf("\nBefore swap : %s  %s",arr[left].str,arr[right].str);
Swap(arr,left,right);
//printf("\nAfter swap : %s  %s\n",arr[left].str,arr[right].str);
}

}

//printf("\n2.pivot Elm is : %s",pivotElm);
strcpy(arr[low].str,arr[right].str);
strcpy(arr[right].str,pivotElm);
//printf("\nRight is : %d",right);
free(pivotElm);
return right;
}


void QuickSort(x arr[],int low,int high){

if(high>low){
//printf("\nIn quicksort");
int pivot=Partition(arr,low,high);
printf("\nWhen pivot is : %d\n",pivot);
int i;
for(i=5;i>=0;i--){
printf("%s",arr[i].str);
}
//printf("\nPivot is : %d",pivot);
QuickSort(arr,low,pivot-1);
QuickSort(arr,pivot+1,high);

}

}

void GetBiggest(x arr[],int n){
//qsort(arr,n,sizeof(x),cmp);
QuickSort(arr,0,n-1);
int i;
//printf("\nin fun");
/*
for(i=n-1;i>=0;i--){
printf("%s",arr[i].str);
}
*/
}

int main(){


//x arr[]={"54","546","548","60"};
//x arr[]={"7","776","7","7"};

x arr[]={"1","34","3","98","9","76"};

int n=sizeof(arr)/sizeof(arr[0]);

printf("\nBiggest number : \n");
GetBiggest(arr,n);

return 0;
}
