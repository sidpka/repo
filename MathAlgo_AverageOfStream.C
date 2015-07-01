#include<stdio.h>
#include<conio.h>

float FindAvg(float prevAvg,int n,int currentNumber){

return (prevAvg*(n-1)+(float)currentNumber)/n;

}

void PrintAverage(int arr[],int n){

float prevAvg=0;

int i;

for(i=0;i<n;i++){

prevAvg=FindAvg(prevAvg,i+1,arr[i]);
printf("\nAverage till now : %f",prevAvg);


}



}



int main(){

int arr[]={10,20,30,40,50,60};
int n=sizeof(arr)/sizeof(arr[0]);

PrintAverage(arr,n);






return 0;
}
