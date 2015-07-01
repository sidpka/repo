#include<stdio.h>
#include<conio.h>

int InterpolationSearch(int* arr,int low,int high,int elm){

int mid;
while(high>=low){

mid=(low)+(high-low)*(elm-arr[low])/(arr[high]-arr[low]);

if(arr[mid]==elm){
return mid;
}else if(arr[mid]>elm){
high=mid-1;;
}else{
low=mid+1;
}

}
return -1;


}

int main(){


int arr[]={1,2,4,6,8,10};

int n=sizeof(arr)/sizeof(arr[0]);
int x=6;
int result=InterpolationSearch(arr,0,n-1,x);

if(result!=-1){
printf("\nFound at location : %d",result+1);
}else{
printf("\nNot found");
}



return 0;
}
