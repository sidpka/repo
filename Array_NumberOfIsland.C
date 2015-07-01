#include<stdio.h>
#include<conio.h>

#define ROW 5
#define COL 5

int IsSafe(int arr[ROW][COL],int row,int col,int visited[ROW][COL]){

if(arr[row][col] && row>=0 && row<ROW && col>=0 && col<COL && visited[row][col]==0){
return 1;
}

return 0;

}

void DFS(int arr[ROW][COL],int row,int col,int visited[ROW][COL]){


int rowNum[]={-1,-1,-1,0,0,1,1,1};
int colNum[]={-1,0,1,-1,1,-1,0,1};

int i;
visited[row][col]=1;
//since there are 8 neighbours
for(i=0;i<8;i++){
if(IsSafe(arr,row+rowNum[i],col+colNum[i],visited)){
DFS(arr,row+rowNum[i],col+colNum[i],visited);
}

}

}

int CountIsland(int arr[ROW][COL]){

int visited[ROW][COL];

int i;
int j;

for(i=0;i<ROW;i++){
for(j=0;j<COL;j++){
visited[i][j]=0;
}
}



int count=0;

for(i=0;i<ROW;i++){
for(j=0;j<COL;j++){

if(arr[i][j] && visited[i][j]==0){
DFS(arr,i,j,visited);
count++;
}

}
}
return count;
}

int main(){

int arr[ROW][COL]={{1,1,0,0,0},
                   {0,1,0,0,1},
                   {1,0,0,1,1},
                   {0,0,0,0,0},
                   {1,0,1,0,1},

};

printf("\nNumber of islands : %d",CountIsland(arr));

return 0;
}
