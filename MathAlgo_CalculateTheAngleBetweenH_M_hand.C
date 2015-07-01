#include<stdio.h>
#include<conio.h>

float FindAngleBetween(int h,int m){


h=h%12;
m=m%60;

float mAngle=6*m;
float hAngle=float(h*60+m)/float(2);
//printf("\nh : %f m : %f",hAngle,mAngle);
float diffAngle=(hAngle-mAngle);
if(diffAngle<0){
diffAngle=-diffAngle;
}

if(360-diffAngle<diffAngle){
diffAngle=360-diffAngle;
}

return diffAngle;
}

int main(){

//int h=9;
//int m=60;

int h=3;
int m=30;

printf("\nAngle between hour and minute hand : %f",FindAngleBetween(h,m));






return 0;
}
