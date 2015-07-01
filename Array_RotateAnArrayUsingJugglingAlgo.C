#include<stdio.h>
#include<conio.h>

int gcd(int d,int n){
if(d==0){
return n;
}
return gcd(n%d,d);


}

void RightRotate(int* arr,int n,int d){


int i;
int j;
int k;
int tmp;

for(i=n-1;i>=(n-gcd(d,n));i--){
tmp=arr[i];
j=i;
while(1){

k=j-d;

if(k<0){
k=k+n;
}

if(k==i){
break;
}

arr[j]=arr[k];
j=k;

}
arr[j]=tmp;
}




/*
for(i=0;i<gcd(d,n);i++){
tmp=arr[i];
j=i;
while(1){

k=j+d;

if(k>=n){
k=k-n;
}

if(k==i){
break;
}

arr[j]=arr[k];
j=k;

}
arr[j]=tmp;
}
*/

}


int main(){
//This method works only if gcd is not 1
int arr[]={1,2,3,4,5,6};

int n=sizeof(arr)/sizeof(arr[0]);

int d;

printf("\nEnter value of d : ");
scanf("%d",&d);

//printf("\n%d",gcd(3,12));
RightRotate(arr,n,d);


printf("\nPress enter to rotate array :\n\n");

int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}


return 0;
}
