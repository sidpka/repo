#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


struct DArray{
char* str;
int index;

};
typedef struct DArray Array;

struct CArrays{

Array* array;
int size;

};
typedef struct CArrays Arrays;


int cmp(const void* a,const void* b ){

return (*(char*)a-*(char*)b);
}



Arrays* Populate(char* word[],int n){


Arrays* tmpNode=(Arrays*)malloc(sizeof(Arrays));

tmpNode->size=n;
tmpNode->array=(Array*)malloc(sizeof(Array)*n);
int i;

for(i=0;i<n;i++){
tmpNode->array[i].str=(char*)malloc(sizeof(char)*strlen(word[i]));
tmpNode->index=i;
strcpy();
}



}


void FindAllAnagrams(char* words[],int n){

//char** tmp=(char**)malloc(sizeof(char*)*n);

int i;
//int index[n];

Arrays * array=Populate(words,n);


for(i=0;i<n;i++){
    tmp[i]=(char*)malloc(sizeof(char)*strlen(words[i]));
strcpy(tmp[i],words[i]);
//printf("\n%s",tmp[i]);
index[i]=i;
}

for(i=0;i<n;i++){
qsort(tmp[i],strlen(tmp[i]),sizeof(char),cmp);
//printf("\n%s",tmp[i]);
}

QuickSort(tmp,index,0,n-1);


}

int main(){

char *words[]={"cat", "dog", "tac", "god", "act"};
int n=5;

FindAllAnagrams(words,n);



return 0;
}
