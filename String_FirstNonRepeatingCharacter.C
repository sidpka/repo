#include<stdio.h>
#include<conio.h>
#include<string.h>

#define No_Of_Char 256


struct CountsArr{

int freq;
int index;

};

typedef struct CountsArr Counts;


void FindFirstNonRepeating(char str[],int n){


int count[No_Of_Char];

int i;

for(i=0;i<No_Of_Char;i++){
count[i]=0;
}

for(i=0;i<n;i++){
count[str[i]]++;
}

for(i=0;i<n;i++){
if(count[str[i]]==1){
printf("First Non Repeating character in string : %c",str[i]);
return;
}
}




}


void FindFirstNonRepeating2(char str[],int n){

Counts count[No_Of_Char];
int i;
for(i=0;i<No_Of_Char;i++){
count[i].freq=0;
count[i].index=-1;
}



for(i=0;i<n;i++){

count[str[i]].freq++;
if(count[str[i]].index==-1){
count[str[i]].index=i;
}
}

int minIndex=n;


for(i=0;i<No_Of_Char;i++){
if(count[i].freq==1){
if(count[i].index<minIndex){
minIndex=count[i].index ;
//printf("\n%d",minIndex);
}
}
}


printf("\nFirst Non Repeating non character : %c",str[minIndex]);

}

int main(){


char str[]="mynameissiddharthpandeymahi";

int n=strlen(str);

//FindFirstNonRepeating(str,n);
FindFirstNonRepeating2(str,n);

return 0;
}
