#include<stdio.h>
#include<conio.h>


void Reverse(int* arr,int n){


int i=0;
int j=n-1;
int tmp;
while(i<j){
tmp=arr[i];
arr[i]=arr[j];
arr[j]=tmp;
i++;
j--;
}
}


int main(){


int arr[]={1,2,3,4,5.6};

int n=sizeof(arr)/sizeof(arr[0]);
int i;
printf("\nArray is : \\n\n\n");
getch();
for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}
getch();
Reverse(arr,n);
printf("\bReversed array is \n\n\n");
getch();
int j;
for(j=0;j<n;j++){
printf("%d  ",arr[j]);
}







return 0;
}
