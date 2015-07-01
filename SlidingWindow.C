#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


int main(){
    int n,k;
printf("\nEnter the size of the array : ");
scanf("%d",&n);

int* Array=(int*)malloc(sizeof(int)*n);

printf("\nEnter the elm of array : \n\n");
int i;

for(i=0;i<n;i++){
scanf("%d",&Array[i]);
}

printf("\n%d node sinserted ...",i);
getch();

printf("\nEnter the value of window : ");
scanf("%d",&k);
printf("\nMax elems\n\n");
int j;
for(i=0;i<=n-3;i++){
int max=0;
for(j=i;j<i+3;j++){
if(Array[j]>max){
max=Array[j];
}

}
printf("%d  ",max);
}











return 0;
}
