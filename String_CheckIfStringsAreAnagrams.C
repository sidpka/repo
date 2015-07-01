#include<stdio.h>
#include<conio.h>
#include<string.h>

int Partition(char str[],int low,int high){

int left=low;
int right=high;

char pivotElm=str[low];

while(left<right){

while(str[left]<=pivotElm){
left++;
}

while(str[right]>pivotElm){
right--;
}

if(left<right){
char tmp;
tmp=str[left];
str[left]=str[right];
str[right]=tmp;
}



}

str[low]=str[right];
str[right]=pivotElm;

return right;



}

void QuickSort(char str[],int low,int high){

if(low<high){

int pivot=Partition(str,low,high);
QuickSort(str,low,pivot);
QuickSort(str,pivot+1,high);



}

}

int FindIfAnagrams_Util(char str1[],char str2[]){

while(*str1 && *str2){

if(*str1==*str2){
str1++;
str2++;
}else{
    return 0;
}

}

if(*str1 || *str2){
return 0;
}else{
return 1;
}


}

int FindIfAnagrams(char str1[],char str2[]){

int len1=strlen(str1);

int len2=strlen(str2);

if(len1!=len2){
return 0;
}

QuickSort(str1,0,len1-1);
QuickSort(str2,0,len2-1);

return FindIfAnagrams_Util(str1,str2);






}

int FindIfAnagrams2(char str1[],char str2[]){

int len1=strlen(str1);
int len2=strlen(str2);

if(len1!=len2){
return 0;
}

int count[256];

int i;

for(i=0;i<256;i++){
count[i]=0;
}

for(i=0;i<len1;i++){
count[str1[i]]++;
count[str2[i]]--;
}

for(i=0;i<256;i++){
if(count[i]){
return 0;
}
}


return 1;

}

int main(){


char str1[]="ABC";
char str2[]="CAB";

/*
if(FindIfAnagrams(str1,str2)){
printf("\nYes");
}else{
printf("\No");
}
*/


if(FindIfAnagrams2(str1,str2)){
printf("\nYes");
}else{
printf("\No");
}




return 0;
}
