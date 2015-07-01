#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define row 4
#define col 5

struct Trie{
int isEnd;
struct Trie* children[2];
};
typedef struct Trie TNode;

TNode* NewNode(){
TNode* tmpNode=(TNode*)malloc(sizeof(TNode));
tmpNode->isEnd=0;
tmpNode->children[0]=NULL;
tmpNode->children[1]=NULL;


return tmpNode;
}

int Insert(TNode** root,int mat[row][col],int r,int c){

if(!(*root)){
(*root)=NewNode();
}

if(c<col){
return Insert(&(*root)->children[mat[r][c]],mat,r,c+1);
}
else{
if(!((*root)->isEnd)){
(*root)->isEnd=1;
return 1;
}else{
return 0;
}

}



}

void PrintUtil(int* arr){
int i;
for(i=0;i<col;i++){
printf("%d  ",arr[i]);
}
printf("\n\n");
}
void PrintUniqueRows(int mat[row][col]){

int i;

TNode* root=NULL;

for(i=0;i<row;i++){
if(Insert(&root,mat,i,0)){
PrintUtil(mat[i]);
}
}



}


int main(){

int mat[row][col]={{0,1,0,0,1},{1,1,0,0,1},{0,1,0,0,1},{1,1,1,1,1}};

PrintUniqueRows(mat);






return 0;
}
