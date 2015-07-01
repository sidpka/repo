#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


struct SuffixArray{

int index;
char* sfx;

};

typedef struct SuffixArray suffix;

int cmp(const void *p0, const void *p1)
{

        return strcmp((*(suffix *) p0).sfx,
                      (*(suffix *) p1).sfx);
}

int* GetSuffixArray(char* text,int n){

suffix array[n];
int i;

for(i=0;i<n;i++){
array[i].index=i;
array[i].sfx=(text+i);
}

qsort(array,n,sizeof(suffix),cmp);

int* sfxArray=(int*)malloc(sizeof(int)*n);

for(i=0;i<n;i++){
sfxArray[i]=array[i].index;
}

return sfxArray;
}

void Search(char * text,char* pat,int n,int* sufxArray){

int m=strlen(pat);

int l,r,mid;

l=0;
r=n-1;
int cnt=0;
while(l<=r){
mid=l+(r-l)/2;
//printf("\nIn %d iteration  index : %d and mid : %d\n",cnt+1,sufxArray[mid],mid);
int result=strncmp(pat,text+sufxArray[mid],m);
cnt++;
if(result==0){
printf("\nPartern found at index : %d",sufxArray[mid]);
return;
}else if(result<0){
r=mid-1;
}else{
l=mid+1;
}
}

printf("\nPattern not found");


}

int main(){

char txt[]="banana";
char pat[]="nan";
int len=strlen(txt);

int* result=GetSuffixArray(txt,len);

int i;
for(i=0;i<len;i++){
printf("%d  ",result[i]);
}

printf("\nPress enter to find pattern in text : ");
getch();
Search(txt,pat,len,result);
getch();


return 0;
}
