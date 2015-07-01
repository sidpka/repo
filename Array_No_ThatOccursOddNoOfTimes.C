#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


//There is just element that occurs odd number of time...


int OddOccurance(int* arr,int n){

int i;
int result=0;

for(i=0;i<n;i++){
    //XOR works here since 1 ^ 1 =0 .. so any number which occurs even number of times results 0.
result=result^arr[i];
}

return result;

}

int main(){
int n;
printf("\nEnter the number of elements in the array : ");
scanf("%d",&n);

printf("\nEnter the elements of the array : ");
int* arr=(int*)malloc(sizeof(int));
int i;

for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
int result=OddOccurance(arr,n);
printf("\n%d occurs odd number of times ...",result);
getch();



return 0;
}
