#include<stdio.h>
#include<conio.h>

void DoUnion(int* a,int* b,int n,int m,int* u,int* indexUnion){

int i=0;
int j=0;
//printf("\nIndex : %d",*indexUnion);
while(i<n && j<m){
if(a[i]<b[j]){
u[(*indexUnion)++]=a[i];
i++;
}else if(a[i]>b[j]){
u[(*indexUnion)++]=b[j];
j++;

}else{
u[(*indexUnion)++]=a[i++];
j++;
}
}

while(i<n){
u[(*indexUnion)++]=a[i++];
}

while(j<m){
u[(*indexUnion)++]=b[j++];
}
}

void DoIntersection(int* a,int* b,int n,int m,int* in,int* index){

int i=0;
int j=0;
//printf("\nIndex is : %d",*index);
//getch();
//printf("\nnis : %d and m is : %d",n,m);
//getch();
while(i<n && j<m){

if(a[i]==b[j]){
    //printf("\nEntering here for : %d and %d",a[i],b[j]);
in[(*index)++]=a[i++];
j++;
}

if(a[i]<b[j]){
i++;
}else if(a[i]>b[j]){
j++;
}

}

//printf("\nReturning : %d\n",*index);
//for(i=0;i<*index;i++){
//printf("%d  ",in[i]);
//}

}


int main(){


int a[]={1,3,5,7};
int b[]={2,3,4,6,7};

int n=sizeof(a)/sizeof(a[0]);
int m=sizeof(b)/sizeof(b[0]);

int u[m+n];
int indexUnion=0;
DoUnion(a,b,n,m,u,&indexUnion);

printf("\nUnion is : \n");
int i;

for(i=0;i<indexUnion;i++){
printf("%d  ",u[i]);
}
int indexIntersection=0;
int in[m<n?m:n];

DoIntersection(a,b,n,m,in,&indexIntersection);

printf("\nIntersection is :\n");

for(i=0;i<indexIntersection;i++){
printf("%d  ",in[i]);
}

return 0;
}
