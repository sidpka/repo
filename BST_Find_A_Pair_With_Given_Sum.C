#include<stdio.h>
#include<stdlib.h>
#include<conio.h>



struct TreeNode{
int data;
struct TreeNode* left,*right;
};
typedef struct TreeNode TNode;

struct StackNode{
TNode* data;
struct StackNode* next;
};
typedef struct StackNode SNode;


TNode* NewNode(int data){
TNode* newNode=(TNode*)malloc(sizeof(TNode));
newNode->data=data;
newNode->right=NULL;
newNode->left=NULL;
return newNode;
}

void Push(SNode** stack,TNode* data){
SNode* tmpNode=(SNode*)malloc(sizeof(SNode));
tmpNode->data=data;
if(!(*stack)){
tmpNode->next=NULL;
(*stack)=tmpNode;
}
else{
tmpNode->next=(*stack);
(*stack)=tmpNode;
}

}

TNode* Pop(SNode** stack){
if(*stack){
SNode* tmpNode=(*stack);
TNode* tmpData=tmpNode->data;
(*stack)=(*stack)->next;
free(tmpNode);
return tmpData;
}
}

int IsEmptyStack(SNode* stack){

return stack==NULL;

}




void Insert(TNode** root,int data){
if(!(*root)){
(*root)=NewNode(data);
}else{
if((*root)->data>data){
Insert(&(*root)->left,data);
}else{
Insert(&(*root)->right,data);
}
}
}


int Search(TNode* root,int data){
if(!root){
return 0;
}
if(root->data==data){
return 1;
}
else if(root->data> data){
return Search(root->left,data);
}else{
return Search(root->right,data);
}
}

void PickNodes(TNode* root,int* buffer,int* i){
if(!root){
return;
}

PickNodes(root->left,buffer,i);
buffer[(*i)++]=root->data;
PickNodes(root->right,buffer,i);


}

int CheckBST(int* buffer,int sum,int n){
int i=0;
int j=n-1;

while(i<j){
if(buffer[i]+buffer[j]==sum){
return 1;
}

if(buffer[i]+buffer[j]<sum){
i++;
}
if(buffer[i]+buffer[j]>sum){
j--;
}

}
return 0;
}

void GetDLL(TNode* root,TNode** head,TNode** tail){

if(!root){
return;
}
if(root->left){
GetDLL(root->left,head,tail);
}
root->left=(*tail);
if((*tail)){
(*tail)->right=root;
}else{
(*head)=root;
}

(*tail)=root;

if(root->right){
GetDLL(root->right,head,tail);
}

}

int CheckAns(TNode* root,int sum){
SNode* stack1=NULL;
SNode* stack2=NULL;
TNode* tmp1=root;
TNode* tmp2=root;

int val1,val2,done1=0,done2=0;

while(1){

while(done1==0){
if(tmp1){

Push(&stack1,tmp1);
tmp1=tmp1->left;
}else{

if(IsEmptyStack(stack1)){
done1=1;
}else{
tmp1=Pop(&stack1);
val1=tmp1->data;
done1=1;
tmp1=tmp1->right;
}
}
}


while(done2==0){
if(tmp2){

Push(&stack2,tmp2);
tmp2=tmp2->right;
}else{

if(IsEmptyStack(stack2)){
done2=1;
}else{
tmp2=Pop(&stack2);
val2=tmp2->data;
done2=1;
tmp2=tmp2->left;
}
}
}

if(val1!=val2 && val1+val2==sum){
return 1;
}
if(val1+val2<sum){
done1=0;
}
if(val1+val2>=sum){
done2=0;
}

if(val1>val2){
return 0;
}
}





}


int CheckIfPresent(TNode* head,TNode* tail,int sum){

if(!head){
return 0;
}

while(head!=tail){

if(head->data+ tail->data==sum){
return 1;
}
if(head->data+tail->data<sum){
head=head->right;
}
if(head->data+tail->data>sum){
tail=tail->left;
}
}
return 0;


}

int main(){
printf("\nEnter the no of nodes you want to insert : ");
int n;
scanf("%d",&n);
int i,data;
TNode* root=NULL;
for(i=0;i<n;i++){
printf("\nEnter data for %d node : ",i);
scanf("%d",&data);
Insert(&root,data);
}
printf("\n%d nodes inserted in BST\n",i);
getch();

/*
printf("\nPress enter to pick nodes\n");
getch();
int* buffer=(int*)malloc(sizeof(int)*n);
int index=0;
PickNodes(root,buffer,&index);
for(i=0;i<n;i++){
printf("%d  ",buffer[i]);
}

printf("\nEnter a value to check if a pair adding to sum exists : ");
scanf("%d",&data);
int result=CheckBST(buffer,data,n);
if(result){
printf("\nSuch pair exists");
}else{
printf("\nDoesn't exist");
}
*/

/*
TNode* head=NULL;
TNode* tail=NULL;
int sum;
GetDLL(root,&head,&tail);
printf("\nEnter sum : ");
scanf("%d",&sum);
int result=CheckIfPresent(head,tail,sum);
if(result){
printf("\nYes");
}else{
printf("\nNo");
}
*/
int sum;
printf("\nEnter sum : ");
scanf("%d",&sum);
int result=CheckAns(root,sum);
if(result){
printf("\nYes");
}else{
printf("\nNo");
}
return 0;
}
