#include<stdio.h>
#include<conio.h>
#include<string.h>

int IsPalindrome(char str[]){

int i=0;
int n=strlen(str)-1;

while(i<n){
if(str[i]!=str[n]){
return 0;
}
i++;
n--;
}

return 1;
}


void Reverse(char str[],int low,int high){

char tmp;

while(low<high){
tmp=str[low];
str[low]=str[high];
str[high]=tmp;
low++;
high--;
}

}


void Rotate(char str[],int n){

Reverse(str,1,n-1);
Reverse(str,0,n-1);

}


int FindIfRotationOfPalindrome(char str[]){

if(IsPalindrome(str)){
return 1;
}

int i;

int n=strlen(str);


for(i=0;i<n-1;i++){
Rotate(str,n);
//printf("\n%s",str);
if(IsPalindrome(str)){
return 1;
}
}

return 0;

}

int main(){

char str[]="aaaab";
int result=FindIfRotationOfPalindrome(str);

if(result){
printf("\nRotation of palindrome ");
}else{
printf("\nNo not palindrome");
}


return 0;
}
