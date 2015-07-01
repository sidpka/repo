#include<stdio.h>
#include<conio.h>


int IsAll9(int num[],int n){

int i;

for(i=0;i<n;i++){
if(num[i]!=9){
return 0;
}
}

return 1;
}


void SetNum(int num[],int n){

int i;
int j;
int carry=0;
int tmp;
if(n&1){
tmp=num[n/2];
num[n/2]=(num[n/2]+1)%10;
carry=(tmp+1)/10;

i=n/2-1;
j=n/2+1;

while(i>=0){
tmp=num[i];
num[i]=(num[i]+carry)%10;
carry=(tmp+carry)/10;
num[j]=num[i];
i--;
j++;

}

}else{

i=n/2-1;
j=n/2;

while(i>=0){
tmp=num[i];
num[i]=(num[i]+carry)%10;
carry=(tmp+carry)/10;
num[j]=num[i];
i--;
j++;

}





}

}


void PrintPalindrome(int num[],int n){

int i;

for(i=0;i<n;i++){
printf("%d  ",num[i]);
}

}

void FindNextSmallerPalindrome(int num[],int n){
int i;
if(IsAll9(num,n)){
printf("1");
for(i=1;i<n;i++){
printf("0");
}
printf("1");

return ;
}

int j;

if(n&1){

i=(n/2)-1;
j=(n/2)+1;
 //printf("\nHere : i :%d , j : %d",i,j);
while( (num[i]==num[j]) && i>=0){
i--;
j++;
}

if(i<0){
SetNum(num,n);

/*
int k;
for(k=0;k<n;k++){
printf("%d  ",num[k]);
}
*/

}else{

if(num[i]<num[j]){
SetNum(num,n);
}else{

while(i>=0){
num[j]=num[i];
i--;
j++;
}


}

}






}else{

i=(n/2)-1;
j=(n/2);
 //printf("\nHere : i :%d , j : %d",i,j);
while( (num[i]==num[j]) && i>=0){
i--;
j++;
}

if(i<0){
SetNum(num,n);

/*
int k;
for(k=0;k<n;k++){
printf("%d  ",num[k]);
}
*/

}else{

if(num[i]<num[j]){
SetNum(num,n);
}else{

while(i>=0){
num[j]=num[i];
i--;
j++;
}


}

}








}



PrintPalindrome(num,n);
}


int main(){

//int num[]={9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2};


//int num[]={3,1,9,1,3};
//int num[]={1 ,4, 5, 8, 7, 6, 7, 8, 3, 2, 2};
int num[]={9,9,9};
int n=sizeof(num)/sizeof(num[0]);

FindNextSmallerPalindrome(num,n);




return 0;
}
