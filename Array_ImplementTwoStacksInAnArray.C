#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct TwoStack{
int top1;
int top2;
int capacity;
int* SArray;
};
typedef struct TwoStack TStack;

TStack* NewNode(int n){
TStack* tmpNode=(TStack*)malloc(sizeof(TStack));
tmpNode->capacity=n;
tmpNode->top1=-1;
tmpNode->top2=n;
tmpNode->SArray=(int*)malloc(sizeof(int)*n);
return tmpNode;
}

void Push1(TStack* root,int data){

if(root->top1+1==root->capacity || root->top1+1==root->top2){
printf("\nOverflow");
}else{
root->SArray[++(root->top1)]=data;
}
}

void Push2(TStack* root,int data){

if(root->top2==0 || root->top1+1==root->top2){
printf("\nOverflow");
}else{
root->SArray[--(root->top2)]=data;
}
}

int Pop1(TStack* root){

if(root->top1==-1){
printf("\nUnderflow");
}else{
return root->SArray[root->top1--];
}

}

int Pop2(TStack* root){

if(root->top2==root->capacity){
printf("\nUnderflow");
}else{
return root->SArray[root->top2++];
}

}

void Traverse1(TStack* root){
int i;

printf("\n|| %d || <--",root->SArray[root->top1]);
for(i=root->top1-1;i>=0;i--){
printf("\n|| %d ||",root->SArray[i]);
}



}

void Traverse2(TStack* root){

int i;

printf("\n|| %d || <--",root->SArray[root->top2]);

for(i=root->top2+1;i<root->capacity;i++){
printf("\n|| %d ||",root->SArray[i]);
}




}

int main(){

printf("\nImplementing two stacks\n");

int ch;
int data;
int n=10;
TStack* root=NewNode(n);
while(1){
printf("\nEnter your choice : ");
printf("\n1.Push Into stack 1: ");
printf("\n2.Pop Stack 1 : ");
printf("\n3.Traverse Stack 1 : ");
printf("\n4.Push Into stack 2: ");
printf("\n5.Pop Stack 2: ");
printf("\n6.Traverse Stack 2: ");
printf("\n0.Exit :\n");

scanf("%d",&ch);

switch(ch){

case 1:
printf("\nEnter data : ");
scanf("%d",&data);
Push1(root,data);
break;

case 2:
printf("\nPopped : %d",Pop1(root));
break;

case 3:
Traverse1(root);
break;

case 4:
printf("\nEnter data : ");
scanf("%d",&data);
Push2(root,data);
break;

case 5:
printf("\nPopped : %d",Pop2(root));
break;

case 6:
Traverse2(root);
break;

case 0:
break;


}

}






return 0;
}
