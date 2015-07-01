#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>



struct Stack{
int top;
int* array;
int n;
};
typedef struct Stack SNode;

SNode* CreateStack(int n){


SNode* tmpNode=(SNode*)malloc(sizeof(SNode));
tmpNode->top=-1;
tmpNode->n=n;
tmpNode->array=(int*)malloc(sizeof(int)*n);

return tmpNode;

}

void Push(SNode* node,int data){
if(node->top<node->n-1){
node->array[ ++node->top ]=data;
}

}

int Pop(SNode* node){
if(node->top>=0){
return node->array[node->top--];
}
}

int min(int a,int b){

return a<b?a:b;
}


void TopologicalSearch(SNode* stack,int visited[],int graph[][26],int node){

visited[node]=1;

int i;

for(i=0;i<26;i++){

if(!visited[i]  && graph[node][i]){
TopologicalSearch(stack,visited,graph,i);
}

}


Push(stack,node);
}


void FindOrderOfLetters(char* words[],int n){

int i;
int j;

int graph[26][26];

for(i=0;i<26;i++){
for(j=0;j<26;j++){
graph[i][j]=0;
}
}

for(i=0;i<n-1;i++){
    int len1=strlen(words[i]);
    int len2=strlen(words[i+1]);
char word1[len1];
char word2[len2];
word1[0]='\0';
word2[0]='\0';

strcpy(word1,words[i]);
strcpy(word2,words[i+1]);

for(j=0;j<min(len1,len2);j++){
if(word1[j]!=word2[j]){
    graph[ word1[j]-'a' ][ word2[j]-'a'  ]=1;
break;
}
}





}


/*
for(i=0;i<26;i++){
for(j=0;j<26;j++){
printf("%d  ",graph[i][j]);
}
printf("\n");
}
*/

SNode* stack=CreateStack(n);

int visited[26]={0};

for(i=0;i<26;i++){
if(!visited[i]){
TopologicalSearch(stack,visited,graph,i);
}
}

printf("\nOrdering of letters \n");

while(stack->top>=0){
printf("%c  ",Pop(stack)+'a');
}

}

int main(){

char* words[]={"caa","aaa","aab"};

int n=3;

FindOrderOfLetters(words,n);




return 0;

}
