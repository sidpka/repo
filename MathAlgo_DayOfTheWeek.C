#include<stdio.h>
#include<conio.h>

int FindDay(int d,int m,int y){

int t[]={0,3,2,5,0,3,5,1,4,6,2,4};

y-=m<3;//We are subtracting 1 from year for every year for monthss jan and feb
//so we are creating one extra day between feb 28 and march 1 for non leap years and 2 for leap years
// so we subtract from offset of months after feb
// {0,3,3,6,1,4,6,2,5,0,3,5}

return (y+y/4-y/100+y/400+t[m-1]+d)%7;

}

int main(){

int d=30;
int m=8;
int y=2010;

printf("\nDay of : %d",FindDay(d,m,y));






return 0;
}
