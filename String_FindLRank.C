#include<stdio.h>
#include<conio.h>
#include<string.h>

int fact(int n){

return (n<=1)?1: n*fact(n-1);
}

int FindSmaller(char str[],int low,int n){

int i;

int count=0;

for(i=low+1;i<n;i++){
if(str[i]<str[low]){
count++;
}
}

return count;

}
int FindRank(char str[]){

int len=strlen(str);

int mul=fact(len);

int countSmaller;

int i;

int rank=1;

for(i=0;i<len;i++){
mul/=(len-i);

countSmaller=FindSmaller(str,i,len);
rank+=countSmaller*mul;
}

return rank;

}

void FindCount(char str[],int count[]){
int i;

for(i=0;str[i];i++){
count[str[i]]++;
}

for(i=1;i<256;i++){
count[i]+=count[i-1];
}



}


void UpdateCount(int count[],char ch){

int i;
for(i=ch;i<256;i++){
count[i]--;
}

}

int FindRank2(char str[]){

int len=strlen(str);


int mul=fact(len);
int count[256]={0};

int rank=1;

FindCount(str,count);
int i;
for(i=0;i<len;i++){
mul/=(len-i);
rank+=count[str[i]-1]*mul;
UpdateCount(count,str[i]);
}

return rank;
}

int main(){


char str[]="STRING";

//printf("\nRank : %d",FindRank(str));

printf("\nRank : %d",FindRank2(str));

return 0;
}
