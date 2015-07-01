#include<stdio.h>
#include<limits.h>
int main(){


int Array[]={10,5,2,99,1,32};
int min_first=INT_MAX;
int min_Second=INT_MAX;

int size=sizeof(Array)/sizeof(Array[0]);
int i;
for(i=0;i<size;i++){

if(Array[i]<min_first){
    min_Second=min_first;
min_first=Array[i];
}else if(Array[i]<min_Second && Array[i]!=min_first )
min_Second=Array[i];

}

printf("\nSecond smaalest is : %d",min_Second);

return 0;
}
