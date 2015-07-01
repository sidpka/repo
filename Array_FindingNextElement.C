#include<stdio.h>
#include<conio.h>
#include<limits.h>
int FindNext(int* arr,int n,int x){

//int index=-1;
//int nextG=INT_MAX;
int i;
/*
for(i=0;i<n;i++){
if(arr[i]>x && arr[i]<nextG){
index=i;
nextG=arr[i];
}
}
*/
int j;
for(j=0;j<n;j++){
if(arr[j]==x){
break;
}
}
for(i=j;i<n;i++){
if(arr[i]>x){
return i;
}
}
return -1;
//return index;

}


void FindNextAll(int* arr,int n){

int max=INT_MIN;

for(i=n-1;i>=0;i--){



}


}

int main(){

int arr[]={2,1,6,3,9,7};

int n=sizeof(arr)/sizeof(arr[0]);

int x;
//for particular elm
/*
printf("\nEnter the value whose next element is to be found : ");
scanf("%d",&x);

int index=FindNext(arr,n,x);

if(index==-1){
printf("\nNo elm");
}else{
printf("\n\nNext element of : %d is : %d",x,arr[index]);
}

*/

printf("\nPress enter to find net elem of all elm : \n");
getch();

FindNextAll(arr,n);
getch();


return 0;
}
