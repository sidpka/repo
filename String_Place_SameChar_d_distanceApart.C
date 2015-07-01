#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256

struct CharFrequency{
int ch;
int freq;
};
typedef struct CharFrequency ChFreq;

int Left(int i,int n){

int left=2*i+1;

if(left<n){
return left;
}else{
return -1;
}


}

int Right(int i,int n){

int right=2*i+2;

if(right<n){
return right;
}else{
return -1;
}


}

void Swap(ChFreq* a,ChFreq* b){

ChFreq tmp=*a;
*a=*b;
*b=tmp;



}

void Heapify(ChFreq heap[],int i,int n){

int left=Left(i,n);
int right=Right(i,n);

int max;

if(left!=-1 && heap[left].freq> heap[i].freq){

max=left;
}else{
max=i;
}

if(right!=-1 && heap[right].freq>heap[max].freq){
max=right;
}

if(max!=i){
Swap(&heap[i],&heap[max]);
Heapify(heap,max,n);
}




}

void BuildHeap(ChFreq heap[],int n){


int i;

i=(n-1)/2;

while(i>=0){
Heapify(heap,i,n);
i--;
}

}


ChFreq RemoveMax(ChFreq heap[],int n){

ChFreq root=heap[0];
if(n>1){
heap[0]=heap[n-1];
Heapify(heap,0,n-1);
}
return root;

}



void PlaceDistance(char str[],int d){

ChFreq array[MAX]={{0,0}};
int n=strlen(str);
int i;
int distinctChar=0;
for(i=0;str[i];i++){
char x=str[i];
if(array[x].ch==0){
array[x].ch=x;
distinctChar++;
}

array[str[i]].freq++;
str[i]='\0';
 }


ChFreq heap[distinctChar];
int j=0;
 for(i=0;i<MAX;i++){
     if(array[i].ch) {

     heap[j++]=array[i];


     }


     }

BuildHeap(heap,distinctChar);



int k;

for(i=0;i<distinctChar;i++){

ChFreq tmp=RemoveMax(heap,distinctChar-i);

k=0;
while(str[k]!='\0'){
k++;
}

for(j=0;j<tmp.freq;j++){
    //printf("\nere for : %d");
if(k+d*j>=n){
printf("\Invalid");
return;
}else{
str[k+j*d]=tmp.ch;
}

}

}





}


int main(){

//char str[]="aabbcc";
char str[]="abb";
int d=2;
PlaceDistance(str,d);
printf("\n%s",str);






return 0;
}
