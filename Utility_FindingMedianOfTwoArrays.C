#include<stdio.h>
#include<conio.h>

int Median(int Array[],int n){

if(n%2==0){
return (Array[n/2] + Array[(n/2) -1])/2;
}else{
return Array[n/2];
}

}

int max(int a,int b){
return (a>b)?a:b;
}

int min(int a,int b){
return (a<b)?a:b;
}

int GetMedian(int A1[],int A2[],int n){

if(n==0){
return -1;
}
if(n==1){
return (A1[0]+A2[0])/2;
}

if(n==2){
return (max(A1[0],A2[0]) + min(A1[1],A2[1]))/2;
}

int median1=Median(A1,n);
int median2=Median(A2,n);

if(median1==median2){
return median1;
}else if(median1<median2){

if(n%2==0){
return GetMedian(A1+(n/2)-1,A2,n-(n/2)+1);
}else{
return GetMedian(A1+(n/2),A2,n-(n/2));
}

}else{

if(n%2==0){
return GetMedian(A1,A2+(n/2)-1,n-(n/2)+1);
}else{
return GetMedian(A1,A2+(n/2),n-(n/2));
}

}



}

int main(){

int n=5;

int Array_One[]={1,12,15,26,38};
int Array_Two[]={2,13,17,30,45};

int median;
median=GetMedian(Array_One,Array_Two,n);

printf("\nMedian is : %d",median);










return 0;
}
