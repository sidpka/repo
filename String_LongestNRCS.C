#include<stdio.h>
#include<conio.h>
#include<string.h>


int FindNRCS(char str[]){


int n=strlen(str);

int i;

int curLen=1;
int maxLen=1;

int visited[256];

for(i=0;i<256;i++){
visited[i]=-1;
}

visited[str[0]]=0;

int prevIndex;
int sIndex;
for(i=1;i<n;i++){

  prevIndex=visited[str[i]];

  if(prevIndex==-1 || i-curLen>prevIndex){
  curLen++;
  }else{

  if(curLen>maxLen){
  maxLen=curLen;
  sIndex=i-curLen;
  }

  curLen=i-prevIndex;


  }

 visited[str[i]]=i;
}

if(curLen>maxLen){
maxLen=curLen;
}

for(i=0;i<maxLen;i++){
printf("%c",str[i+sIndex]);
}

getch();
return maxLen;


}

int main(){


char str[]="GEEKSFORGEEKS";

printf("\nLongest length non-repeating substring : %d",FindNRCS(str));





return 0;
}
