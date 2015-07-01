#include<stdio.h>
#include<conio.h>


void ShellSort(int* arr,int n){

int i,j,h;
int tmp;

for(h=n/2;h>0;h=h/2){

for(i=h;i<n;i++){

tmp=arr[i];
j=i;

while(j>=h && arr[j-h]>tmp){
arr[j]=arr[j-h];
j-=h;
}
arr[j]=tmp;

}


}

}

int main(){


int arr[]={2,1,4,3,8,6,7};

int n=sizeof(arr)/sizeof(arr[0]);

ShellSort(arr,n);

printf("\nSorted\n");

int i;

for(i=0;i<n;i++){
printf("%d  ",arr[i]);
}

return 0;
}
