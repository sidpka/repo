#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

struct Tournament{
int count;
int* TArray;
};
typedef struct Tournament TNode;

TNode* CreateTournament(int n){
TNode* tmpNode=(TNode*)malloc(sizeof(TNode));
tmpNode->count=n;
int height=ceil(log2(n));
int size=(int)pow(2,height+1)-1;
tmpNode->TArray=(int*)malloc(sizeof(int)*size);

int i;
int start=(int)pow(2,height)-1;
for(i=start;i<size;i++){
tmpNode->TArray[i]=INT_MIN;
}
return tmpNode;
}

int max(int a,int b){
return a>b?a:b;
}

int Left(int i){
return 2*i+1;
}

int Right(int i){
return 2*i+2;
}

void StartTournament(TNode* node,int height){

int i;
int start=(int)pow(2,height)-2;
i=start;
//printf("\nStart is : %d",i);
while(i>=0){
node->TArray[i]=max(node->TArray[Left(i)],node->TArray[Right(i)]);
//printf("\nUpdating [%d] with : %d",i,node->TArray[i]);
i--;
}



}


int FindRunnerUp(TNode* node,int height){

int endLocation=(int)pow(2,height)-2;

int winner=node->TArray[0];

int i=0;
int sWinner=INT_MIN;
int left,right;
while(i<=endLocation){
left=node->TArray[Left(i)];
right=node->TArray[Right(i)];

if(left==winner){
 if(sWinner<right){
 sWinner=right;
 }
 i=Left(i);
}else{
 if(sWinner<left){
 sWinner=left;
 }
 i=Right(i);


}


}

return sWinner;

}

int main(){

int n;
printf("\nEnter the number of players : ");
scanf("%d",&n);
TNode* tm=CreateTournament(n);

printf("\nEnter the strength of the players : ");
int i;
int data;
int height=ceil(log2(n));
int size=(int)pow(2,height+1)-1;
int start=(int)pow(2,height)-1;

for(i=start;i<size;i++){
printf("\nStrength of Player[%d] : ",i-start);
scanf("%d",&tm->TArray[i]);
}

StartTournament(tm,height);

printf("\nWinner is : %d",tm->TArray[0]);
int runnerUp=FindRunnerUp(tm,height);
printf("\nRunner up is : %d",runnerUp);
return 0;
}
