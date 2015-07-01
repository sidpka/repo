#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

float FindArea(int x1,int y1,int x2,int y2,int x3,int y3){

return abs(( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )/2.0);


}

int FindIfInside(int X[],int Y[],int Px,int Py){

float totalArea=FindArea(X[0],Y[0],X[1],Y[1],X[2],Y[2]);

float A1=FindArea(X[0],Y[0],X[1],Y[1],Px,Py);
float A2=FindArea(X[0],Y[0],X[2],Y[2],Px,Py);
float A3=FindArea(X[2],Y[2],X[1],Y[1],Px,Py);

printf("%f",totalArea);
printf("\n%f",A1+A2+A3);

return totalArea==(A1+A2+A3);

}

int main(){

int X[]={0,20,10};
int Y[]={0,0,30};

int Px=10;
int Py=15;

//int result=FindIfInside(X,Y,Px,Py);

//result?printf("\nInside"):printf("\nOutside");

int x=3;

printf("%f",3/2.0);


return 0;
}
