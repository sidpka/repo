#include<stdio.h>
#include<conio.h>
#define V 5

void PrintPath(int buffer[]){
int k;
for(k=0;k<V;k++){
printf("%d  ",buffer[k]);
}
printf("%d",buffer[0]);

}


int IsValidEdge(int mat[V][V],int buffer[],int index,int vertex){


if(index==0){
return 1;
}

if(mat[buffer[index-1]][vertex]==0){
return 0;
}

int i;

for(i=0;i<index;i++){
if(buffer[i]==vertex){
return 0;
}
}


return 1;


}


int FindHamiltonianPath_Util(int mat[V][V],int buffer[],int index){
if(index==V && mat[buffer[index-1]][buffer[0]]){
return 1;
}else if(index==V){
return 0;
}

int i;

for(i=0;i<V;i++){

if(IsValidEdge(mat,buffer,index,i)){

buffer[index]=i;

if(FindHamiltonianPath_Util(mat,buffer,index+1)){
return 1;
}else{
buffer[index]=-1;
}

}

}

return 0;

}




void FindHamiltonianPath(int mat[V][V]){


int buffer[V];

int k;

for(k=0;k<V;k++){
buffer[k]=-1;
}

if(FindHamiltonianPath_Util(mat,buffer,0)){
PrintPath(buffer);
}else{
printf("\nHamlitonian cycle not possible \n");
}



}


int main(){

int mat[V][V]={{0,1,0,1,0},
                {1,0,1,1,1},
                {0,1,0,0,1},
                {1,1,0,0,1},
                {0,1,1,1,0}};


FindHamiltonianPath(mat);




return 0;
}
