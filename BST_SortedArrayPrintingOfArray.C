#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void SortedPrint(int Arr[],int start,int end){

if(start>end){
return;
}
SortedPrint(Arr,2*start+1,end);
printf("%d   ",Arr[start]);
SortedPrint(Arr,2*start+2,end);

}

int main(){

int Arr[]={4,2,5,1,3};
int n=sizeof(Arr)/sizeof(Arr[0]);
printf("\nPress enter to see sorted array :\n\n");
getch();
SortedPrint(Arr,0,n-1);
printf("\n\n");
getch();







return 0;
}
