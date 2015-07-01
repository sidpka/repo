#include<stdio.h>
#include<conio.h>


int FindWays(int* scores,int m,int n){

int count[n+1];


int i;
int j;

for(i=0;i<=n;i++){
count[i]=0;
}

count[0]=1;

for(j=0;j<m;j++){

for(i=scores[j];i<=n;i++){
count[i]+=count[i-scores[j]];
}

}



/*
for(i=0;i<=n;i++){
printf("%d  ",count[i]);
}
getch();
*/

return count[n];

}

int main(){


int scores[]={3,5,10};
int m=sizeof(scores)/sizeof(scores[0]);
int n=20;

printf("\nNo of ways to reach score[%d] is : %d",n,FindWays(scores,m,n));





return 0;
}
