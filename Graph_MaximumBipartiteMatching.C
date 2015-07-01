#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int AllocationProcess(int** array,int employee,int* visited,int* allocationRegister,int n){

int i;

for(i=0;i<n;i++){
if(array[employee][i] && !visited[i]){

visited[i]=1;

if(allocationRegister[i]<0 || AllocationProcess(array,allocationRegister[i],visited,allocationRegister,n)){
allocationRegister[i]=employee;
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

return result;





}

int main(){

int m,n;

printf("\nEnter the no of jobs and applicants : ");

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
printf("\nEnter the applicant and his interest : ");
int a,s;
for(i=0;i<r;i++){
printf("\nApplicant : Job : ");
scanf("%d %d",&a,&s);
array[a][s]=1;
}

int result;
printf("\nPress enter to see the no of employeee getting job : ");
//MBM-- Maximum Bipartite Matching
result=MBM(array,m,n);
getch();
printf("\n%d Employees got a job ",result);


return 0;
}
