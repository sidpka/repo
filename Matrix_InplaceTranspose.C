#include<stdio.h>
#include<conio.h>




void PrintArray(int* arr,int row,int col){

int i;
int j;

for(i=0;i<row;i++){
for(j=0;j<col;j++){
printf("%d  ",*(arr + col*i+ j));
}
printf("\n");
}


}

void Swap(int *x,int *yy){

*x+=*yy;
*yy=*x-*yy;
*x-=*yy;
}

void Transpose(int* arr,int row,int col){

int size=row*col-1;

int visited[size+1];
int j;

for(j=0;j<size+1;j++){
visited[j]=0;
}
visited[0]=1;
visited[size]=1;

int tmp;
int nextPosition;


int cycleStartPoint;

int i=1;

while(i<size){


cycleStartPoint=i;
tmp=arr[i];
do{

nextPosition=(i*row)%size;
//printf("%d  ",arr[nextPosition]);
Swap(&arr[nextPosition],&tmp);
//printf("\n%d  ",arr[nextPosition]);
//getch();
visited[i]=1;
i=nextPosition;
}while(i!=cycleStartPoint);

for(i=1;i<size && visited[i];i++);

}






}


int main(){
 int row=3;
 int col=4;
int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};

PrintArray(arr,row,col);
Transpose(arr,row,col);
printf("\n\n");
PrintArray(arr,col,row);






return 0;
}
