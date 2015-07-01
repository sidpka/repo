#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>


void FindTeam_Util(int* arr,int n,int sum,int* minDiff,int* currentTeam,int* solutionTeam,int noOfSelectedElements,int currentSum,int currentPos){

if(currentPos==n){
   // printf("\n11");
return;
}

if((n/2 - noOfSelectedElements)>(n-currentPos)){
    //printf("\n16");
return;
}

FindTeam_Util(arr,n,sum,minDiff,currentTeam,solutionTeam,noOfSelectedElements,currentSum,currentPos+1);

noOfSelectedElements++;
currentSum+=arr[currentPos];
currentTeam[currentPos]=1;
//printf("\nHere");
if(noOfSelectedElements==n/2){
//printf("\nHere");
if(abs(sum/2 - currentSum)<(*minDiff)){

(*minDiff)=abs(sum/2 -currentSum);
int i;

for(i=0;i<n;i++){
solutionTeam[i]=currentTeam[i];
}


}
}
else{

FindTeam_Util(arr,n,sum,minDiff,currentTeam,solutionTeam,noOfSelectedElements,currentSum,currentPos+1);


}
currentTeam[currentPos]=0;
}





void FindTeams(int* arr,int n){

int minDiff=INT_MAX;

int* currentTeam=(int*)malloc(sizeof(int)*n);
int* solutionTeam=(int*)malloc(sizeof(int)*n);

int sum=0;

int i;

for(i=0;i<n;i++){
sum+=arr[i];
currentTeam[i]=0;
solutionTeam[i]=0;
}
//printf("\nsum : %d",sum);
FindTeam_Util(arr,n,sum,&minDiff,currentTeam,solutionTeam,0,0,0);



printf("\nFirst Team : \n");

//int i;

for(i=0;i<n;i++){
if(solutionTeam[i]){
printf("%d  ",arr[i]);
}
}

printf("\nSecond Team : \n\n");

for(i=0;i<n;i++){
if(solutionTeam[i]!=1){
printf("%d  ",arr[i]);
}
}




}





int main(){

int arr[]={23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
int n=sizeof(arr)/sizeof(arr[0]);

FindTeams(arr,n);


return 0;
}





