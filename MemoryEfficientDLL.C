#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct DoublyLinkedList{
int data;
struct DoublyLinkedList* pointerDiff;
};
typedef struct DoublyLinkedList DLL;


void TraverseDLL(DLL* head){

DLL*tmpNode=head;
DLL* prev=NULL;
DLL* tmpHolder;
while(tmpNode){
printf("%d --> ",tmpNode->data);
tmpHolder=tmpNode;
tmpNode=(DLL*)((int)tmpNode->pointerDiff ^ (int)prev);
prev=tmpHolder;
}

}


void InsertDLL(DLL** head,DLL** end,int data){
DLL* newNode=(DLL*)malloc(sizeof(DLL));
newNode->data=data;

DLL* tmpNode;

if(!(*head)){
newNode->pointerDiff=NULL;
(*head)=newNode;
(*end)=newNode;
}else{
if((*head)==(*end)){
tmpNode=(*head);
(*end)->pointerDiff=(DLL*)((int)(newNode)^(int)(NULL));
newNode->pointerDiff=(DLL*)(((int)NULL^(int)tmpNode));
(*head)=newNode;
}else{
tmpNode=(DLL*)((int)((*head)->pointerDiff)^(int)NULL);
(*head)->pointerDiff=(DLL*)((int)tmpNode^(int)newNode);
newNode->pointerDiff=(DLL*)((int)(*head)^(int)NULL);
(*head)=newNode;
}
}
}


int main(){

int n;

printf("\nEnter the number of nodes : ");
scanf("%d",&n);
DLL* head=NULL;
DLL* end=NULL;
int i;
int data;
for(i=0;i<n;i++){
printf("\nEnter data of your node : ");
scanf("%d",&data);
InsertDLL(&head,&end,data);
}
printf("\n%d nodes added \n",i);
getch();
printf("\nPress enter to traverse \n");
getch();
TraverseDLL(head);
getch();
printf("\nPress enter to traverse back\n");
getch();

TraverseDLL(end);
getch();

return 0;
}
