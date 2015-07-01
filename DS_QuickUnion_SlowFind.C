#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int* MakeSet(int size){

int* array=(int*)malloc(sizeof(int)*size);
int i;
for(i=0;i<size;i++){
array[i]=i;
}
return array;
}

int Find(int* Array,int x,int n){

if(x<0 || x>=n){
return -1;
}
if(Array[x]==x){
return x;
}else{
return Find(Array,Array[x],n);
}

}



void Traverse(int* Array,int n){

int i;

for(i=0;i<n;i++){
printf("%d  ",Array[i]);
}

}

void MakeUnion(int* Array,int parent,int child,int n){

if(Find(Array,parent,n)==Find(Array,child,n)){
return;
}

if(!((parent>=0 && parent<n) && (child>=0 && child<n))){
return;
}

else{
Array[child]=parent;
}

int i;

for(i=0;i<n;i++){
if(Array[i]==child){
Array[i]=parent;
}
}

}

int main(){



int n;
printf("\nEnter the number of elements :  ");
scanf("%d",&n);
int *Array=MakeSet(n);

int i;

printf("\nInitially set :\n");

Traverse(Array,n);

printf("\nPress enter to make union\n");
getch();
int ch;
int parent,child;
while(1){
printf("\nEnter your choice \n");
printf("\n1.Union");
printf("\n2.Find");
printf("\n3.Traverse");
printf("\n4.Exit\n");
scanf("%d",&ch);

switch(ch){
case 1:
printf("\nEnter parent , child \n");
scanf("%d %d",&parent,&child);
MakeUnion(Array,parent,child,n);
break;

case 2:
printf("\nEnter an element to find root of : ");
scanf("%d",&child);
printf("\nParent of %d is :  %d\n",child,Array[child]);
break;
case 3:
Traverse(Array,n);
break;

case 4:
return 0;

}
getch();

}


return 0;
}
