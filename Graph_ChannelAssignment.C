#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int AllocationProcess(int** array,int transmitter,int* visited,int* allocationRegister,int n){

int i;

for(i=0;i<n;i++){
if(array[transmitter][i]>0 && !visited[i]){

visited[i]=1;

if(allocationRegister[i]<0 || AllocationProcess(array,allocationRegister[i],visited,allocationRegister,n)){
allocationRegister[i]=transmitter;
return 1;
}

}
}
return 0;
}

void SetSeen(int* visited,int n){
int i;
for(i=0;i<n;i++){
visited[i]=0;
}
}

int MBM(int** array,int m,int n){

int* visited=(int*)malloc(sizeof(int)*n);
int* allocationRegister=(int*)malloc(sizeof(int)*n);
int i;
for(i=0;i<n;i++){
allocationRegister[i]=-1;
}
int result=0;
for(i=0;i<m;i++){
//int* visited=(int*)malloc(sizeof(int)*n);
//memset(visited,0,sizeof(visited));
SetSeen(visited,n);
if(AllocationProcess(array,i,visited,allocationRegister,n)){
result++;
}

}

for(i=0;i<n;i++){
if(allocationRegister[i]!=-1){
printf("\nTx[%d] --=- > Rx[%d]",allocationRegister[i],i);
}

}

return result;





}

int main(){

int m,n;

printf("\nEnter the no of receivers and transmitters : ");

scanf("%d %d",&n,&m);
int** array=(int**)malloc(sizeof(int*)*m);
int i,j;

for(i=0;i<m;i++){
array[i]=(int*)malloc(sizeof(int)*n);
}

for(i=0;i<m;i++){
for(j=0;j<n;j++){
array[i][j]=0;
}
}

int r;
printf("\nEnter the no of relation : ");
scanf("%d",&r);
printf("\nEnter the transmitters and the receiver it has packets to send  : ");
int a,s,p;
for(i=0;i<r;i++){
printf("\Transmitter : Receiver and no of packets: ");
scanf("%d %d %d",&a,&s,&p);
array[a][s]=p;
}

int result;
printf("\nPress enter to see the no of packets transmitted during a time slot: ");
//MBM-- Maximum Bipartite Matching
result=MBM(array,m,n);
getch();
printf("\n\n%d packets can be transmitted during a time slot ",result);


return 0;
}
