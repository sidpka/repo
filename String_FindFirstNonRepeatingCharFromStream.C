#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define Max_Char 256


struct DLL{
char data;
struct DLL* next,*prev;
};
typedef struct DLL DNode;

DNode* NewNode(char data){

DNode* tmpNode=(DNode*)malloc(sizeof(DNode));

tmpNode->data=data;
tmpNode->next=NULL;
tmpNode->prev=NULL;


}

void Insert(DNode** head,DNode** tail,char data){

DNode* tmpNode=NewNode(data);

if(!(*head)){
(*head)=(*tail)=tmpNode;
}else{

(*tail)->next=tmpNode;
tmpNode->prev=(*tail);
(*tail)=tmpNode;
}




}


void Remove(DNode** head,DNode** tail,DNode* node){


if(*head==*tail && *tail==node){
*head=NULL;
*tail=NULL;
return;
}

if(*tail==node){
(*tail)->prev->next=NULL;
(*tail)=(*tail)->prev;
return;
}

if(*head==node){
(*head)->next->prev=NULL;
(*head)=(*head)->next;
return;
}

node->prev->next=node->next;
node->next->prev=node->prev;
node=NULL;




}


void PrintStream(char str[]){

int i;

int visited[Max_Char];
DNode* isInDLL[Max_Char];

for(i=0;i<Max_Char;i++){
visited[i]=0;
isInDLL[i]=NULL;
}

i=0;

DNode* head=NULL;
DNode* tail=NULL;

while(str[i]){

if(visited[str[i]]){

if(isInDLL[str[i]]){
DNode* tmpNode=isInDLL[str[i]];
Remove(&head,&tail,tmpNode);
isInDLL[str[i]]=NULL;
}

}else{
visited[str[i]]=1;
Insert(&head,&tail,str[i]);
isInDLL[str[i]]=tail;
}

printf("\nFirst non repeating character : %c",head->data);
i++;

}




}

int main(){


char str[]="abcdaabfdc";
PrintStream(str);





return 0;
}
