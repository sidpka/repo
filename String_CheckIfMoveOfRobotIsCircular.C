#include<stdio.h>
#include<conio.h>
#include<string.h>

#define E 0
#define N 1
#define W 2
#define S 3


int FindIfCircularMove(char str[]){

int n=strlen(str);

char direction='E';

int X=0;
int Y=0;
int i;

for(i=0;i<n;i++){

if(direction=='E'){

if(str[i]=='G'){
X+=1;
}else if(str[i]=='L'){
direction='N';
}else{
direction='S';
}

}else if(direction=='N'){

if(str[i]=='G'){
Y+=1;
}else if(str[i]=='L'){
direction='W';
}else{
direction='E';
}

}else if(direction=='W'){

if(str[i]=='G'){
X-=1;
}else if(str[i]=='L'){
direction='S';
}else{
direction='N';
}

}else if(direction=='S'){

if(str[i]=='G'){
Y-=1;
}else if(str[i]=='L'){
direction='E';
}else{
direction='W';
}

}


}


if(X==0 && Y==0){
return 1;
}else{
return 0;
}





}


int FindIfCircularMove2(char str[]){

int direction=E;

int n=strlen(str);

int i;

int x=0;
int y=0;

for(i=0;i<n;i++){

if(str[i]=='L'){
direction=(direction+1)%4;
}else if(str[i]=='R'){
direction=(direction-1)%4;
}else{

if(direction==E){
x++;
}else if(direction==N){
y++;
}else if(direction==W){
x--;
}else if(direction==S){
y--;
}


}



}

return (x==0 && y==0);

}



int  main(){

char str[]="GLGLGLG";

//int result=FindIfCircularMove(str);

int result=FindIfCircularMove2(str);

result==1?printf("\nYes Circular"):printf("\nNo Not circular");




return 0;
}
