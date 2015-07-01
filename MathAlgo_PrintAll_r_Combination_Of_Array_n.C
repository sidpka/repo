#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void PrintCombinations_Util(int arr[],int n,int r,int buffer[],int index,int k){

int i;

if(index==r){
for(i=0;i<index;i++){
printf("%d  ",buffer[i]);
}
printf("\n");
return;
}

for(i=k;i<n-r+index+1;i++){
//for(i=k;i<=n && n-i+1>=r-index;i++){
buffer[index]=arr[i];
while(arr[i]==arr[i+1]){
i++;
}
PrintCombinations_Util(arr,n,r,buffer,index+1,i+1);

}


}


int cmp(const void* a,const void* b){

return *(int*)a-*(int*)b;
}

void PrintCombinations(int arr[],int n,int r){

int buffer[r];
qsort(arr,n,sizeof(int),cmp);
PrintCombinations_Util(arr,n,r,buffer,0,0);



}

int main(){

//int arr[]={1,2,3,4};
int arr[]={1,2,1};
int n=sizeof(arr)/sizeof(arr[0]);
int r=2;

PrintCombinations(arr,n,r);




return 0;
}
