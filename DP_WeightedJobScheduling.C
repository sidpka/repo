#include<stdio.h>
#include<conio.h>

void PrintSelectedJob(int s[],int f[],int n){

int i=0;
printf("\nJob : %d",i);
int j;
for(j=1;j<n;j++){

if(s[j]>=f[i]){
printf("\nJob : %d",j);
i=j;
}


}

}

int main(){

int s[]={1,3,0,5,8,5};
int f[]={2,4,6,7,9,9};
int n=sizeof(s)/sizeof(s[0]);


printf("\nFollowing jobs selected : \n");
PrintSelectedJob(s,f,n);




return 0;
}
