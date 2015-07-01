#include<stdio.h>
#include<conio.h>
#include<string.h>

#define No_Of_Char 256

void FindContainingWords(char* list[],int n, char word[]){

int i;

/*
for(i=0;i<n;i++){
printf("\n%s",list[i]);
}
*/

int count[No_Of_Char];

for(i=0;i<No_Of_Char;i++){
count[i]=0;
}

for(i=0;word[i];i++){
count[word[i]]++;
}

int j;

int tmp[No_Of_Char];



for(i=0;i<n;i++){

for(j=0;j<No_Of_Char;j++){
tmp[j]=count[j];
}

for(j=0;list[i][j];j++){
if(tmp[list[i][j]]){
tmp[list[i][j]]--;
}
}


for(j=0;j<No_Of_Char;j++){
if(tmp[j]){
break;
}
}

if(j==No_Of_Char){
printf("\n%s",list[i]);
}

}


}

int main(){

char* list[]={"sunday","geeksforgeeks","utensils","just","sss"};
int n=5;

char word[]="sun";

FindContainingWords(list,n,word);




return 0;
}
