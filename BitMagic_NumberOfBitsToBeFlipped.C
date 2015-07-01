#include<stdio.h>
#include<conio.h>

#define Group_A(x) x,x+1,x+1,x+2
#define Group_B(x) Group_A(x),Group_A(x+1),Group_A(x+1),Group_A(x+2)
#define Group_C(x) Group_B(x),Group_B(x+1),Group_B(x+1),Group_B(x+2)

#define Meta_Table(Parameter)\
Group_##Parameter(0), \
Group_##Parameter(1), \
Group_##Parameter(2), \
Group_##Parameter(3), \

int CountSetBits(int num){

static unsigned char const lookUp[]={ Meta_Table(C) };

unsigned char* p=NULL;

int count=0;
p=(unsigned char*)&num;
count+=lookUp[p[0]];
count+=lookUp[p[1]];
count+=lookUp[p[2]];
count+=lookUp[p[3]];

return count;



}

int CheckBitFlipps(int a,int b){


int c=a^b;

/*
int count=0;

while(c){
c=c&(c-1);
count++;
}


return count;
*/

return CountSetBits(c);
}



int main(){

int a=4;
int b=8;

printf("\nNumber of bits to be flipped : %d",CheckBitFlipps(a,b));



return 0;
}
