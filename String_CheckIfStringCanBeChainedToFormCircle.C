#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


int FindIfChainable(char* str[],int orders[],int n){

int visited[n];

int i;

for(i=0;i<n;i++){
visited[i]=0;
}

int j;
i=0;
visited[0]=1;
orders[0]=0;
char firstChar=str[orders[0]][0];
//printf("%c",firstChar);
i++;
while(i<n){
//printf("\nHere");
    for(j=0;j<n;j++){
        int len=strlen(str[j]);
    if(visited[j]==0 && str[j][len-1]==firstChar){
    visited[j]=1;
    orders[i]=j;
    firstChar=str[j][0];
    break;
    }
    }
    if(j==n){
    return 0;
    }

    i++;

}

int len=strlen(str[0]);
if(str[orders[n-1]][0]!=str[ orders[0]][len-1] ){
return 0;
}



return 1;

}

int main(){

char* str[]={"for","geek","rig","kaf"};
//char* str[]={"aaa","bbb"};
int n=4;

int orders[4]={-1};
int result=FindIfChainable(str,orders,n);

if(result){
printf("\nYes\n");
int i;

for(i=n-1;i>=0;i--){
printf("%s    ",str[orders[i]]);
}

}else{
printf("\nNo");
}



return 0;

}
