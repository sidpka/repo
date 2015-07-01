#include<stdio.h>
#include<conio.h>


void PrintCommon(int* a,int* b,int* c,int u,int v,int w){


int hash[200];

int i;

for(i=0;i<200;i++){
hash[i]=0;
}


for(i=0;i<u;i++){
hash[a[i]]++;
}

for(i=0;i<v;i++){
hash[b[i]]++;
}

for(i=0;i<w;i++){
hash[c[i]]++;
}

for(i=0;i<100;i++){
if(hash[i]==3){
printf("%d  ",i);
}
}


}


void PrintCommon2(int* a,int* b,int* c,int u,int v,int w){

int i=0;
int j=0;
int k=0;

while(i<u && j<v && k<w){

if(a[i]==b[j] && b[j]==c[k]){
printf("%d  ",a[i]);
i++;
j++;
k++;
}

else if(a[i]<b[j]){
i++;
}
else if(b[j]<c[k]){
j++;
}else{
k++;
}

}




}

int main(){

int a[]={1,5,10,20,40,80};
int u=sizeof(a)/sizeof(a[0]);

int b[]={6,7,20,80,100};
int v=sizeof(b)/sizeof(b[0]);

int c[]={3,4,15,20,30,70,80,120};
int w=sizeof(c)/sizeof(c[0]);
//O(u+v+w) extra space
//PrintCommon(a,b,c,u,v,w);

//O(n) time

PrintCommon2(a,b,c,u,v,w);




return 0;
}
