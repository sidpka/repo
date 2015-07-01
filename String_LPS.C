#include<stdio.h>
#include<conio.h>
#include<string.h>

int FindLPS(char str[]){

int len=strlen(str);
int maxLen=1;

int i;
int low;
int high;

for(i=1;i<len;i++){

low=i-1;
high=i;

while( (low>=0 && high<len) && (str[low]==str[high])){

if((high-low+1)>maxLen){
maxLen=high-low+1;
}
low--;
high++;
}

low=i-1;
high=i+1;

while( (low>=0 && high<len) && (str[low]==str[high])){

if((high-low+1)>maxLen){
maxLen=high-low+1;
}
low--;
high++;
}


}

return maxLen;

}

int main(){

char str[]="forgeeksskeegfor";


printf("\nLength of longest palindromic substring : %d",FindLPS(str));






return 0;
}
