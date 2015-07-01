#include<stdio.h>
#include<conio.h>


int FindSubsetSum(int weights[],int n,int target,int buffer[]){

int i;

if(target==0){
return 1;
}

if(target<0 || n<=0){
return 0;
}

for(i=n-1;i>=0;i--){
buffer[i]=1;
if(FindSubsetSum(weights,i,target-weights[i],buffer)){
return 1;
}else{
buffer[i]=0;
}
}

return 0;

}


int main(){


int weights[]={15,22,14,26,32,9,16,8,};
//int weights[]={2,3,8};
int n=sizeof(weights)/sizeof(weights[0]);

int target=53;

//int target=5;

int buffer[n];




int i;

for(i=0;i<n;i++){
buffer[i]=0;
}


int result=FindSubsetSum(weights,n,target,buffer);

if(result){
printf("\nSum exists\n");

for(i=0;i<n;i++){
if(buffer[i]){
printf("%d ",weights[i]);
}
}


}else{
printf("\Doesn't exist");
}







return 0;
}
