#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void AlignRight(int* array,int size){

int i;
int j=size-1;
for(i=size-1;i>=0;i--){
if(array[i]!=-1){
array[j]=array[i];
j--;
}
}


}

void MergeArray(int* bigArray,int* smallArray,int sizeBig,int sizeSmall){

int i=0;
int j=0;
int k=0;

i=sizeSmall;

while(k<sizeBig){

if((i<sizeBig && bigArray[i]<smallArray[j]) || j==sizeSmall){
bigArray[k++]=bigArray[i++];
}else{
bigArray[k++]=smallArray[j++];
}

}

}

int main(){

int bigArray[10]={1,-1,4,-1,-1,6,-1,8,-1,9};
int smallArray[5]={2,5,7,10,11};

printf("\nPress enter to compress array to right : \n");
getch();

AlignRight(bigArray,10);

printf("\nPress enter to see modified array : \n");
getch();

int i;

for(i=0;i<10;i++){
printf("%d  ",bigArray[i]);
}

MergeArray(bigArray,smallArray,10,5);

printf("\nPress enter to see merged array : \n");
getch();

for(i=0;i<10;i++){
printf("%d  ",bigArray[i]);
}






return 0;
}
