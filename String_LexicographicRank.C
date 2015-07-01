#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int Partition(char str[],int low,int high){

int left=low;
int right=high;

char pivotElm=str[low];

while(left<right){

while(str[left]<=pivotElm){
left++;
}

while(str[right]>pivotElm){
right--;
}

if(left<right){
char tmp;

tmp=str[left];
str[left]=str[right];
str[right]=tmp;
}



}

str[low]=str[right];
str[right]=pivotElm;

return right;


}

void QuickSort(char str[],int low,int high){


if(low<high){

int pivot=Partition(str,low,high);
QuickSort(str,low,pivot-1);
QuickSort(str,pivot+1,high);


}



}

void Swap(char* a,char* b){

char tmp;
tmp=*a;
*a=*b;
*b=tmp;

}

int FindRank(char tmp[],int len,char str[],int index,int* rank){

if(index==len){
//printf("\n%s",tmp);
//return ;
*rank++;
printf("\nRank : %d",*rank);
}

int i;
for(i=index;i<len;i++){
Swap(&tmp[index],&tmp[i]);

if(FindRank(tmp,len,str,index+1,rank)){
return 0;
}


Swap(&tmp[index],&tmp[i]);

}



}






int FindLexicographicRank(char str[]){

int len=strlen(str);
char* tmp=(char*)malloc(sizeof(char)*(len+1));
strcpy(tmp,str);
//printf("\n%s",tmp);
QuickSort(tmp,0,len-1);
//printf("\n%s\n%s",str,tmp);

int rank=1;

return FindRank(tmp,len,str,0,&rank);

}

int main(){

char str[]="bca";

int result=FindLexicographicRank(str);






return 0;
}
