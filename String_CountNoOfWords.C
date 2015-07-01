#include<stdio.h>
#include<conio.h>
#include<string.h>


int FindCount(char str[]){

int n=strlen(str);

//printf("\n%d",n);

int i=0;
int count=0;
int prev=0;

while(str[i]){

if(str[i]==' ' || str[i]=='\t' || str[i]=='\n'){
prev=0;
}else{

if(prev==0){
count++;
prev=1;
}

}

i++;


}

return count;
}

int main(){


char str[]="One two          three\n  four\nfive  ";

printf("\nNo of words : %d",FindCount(str));


return 0;
}
