#include<stdio.h>
#include<conio.h>

int Min(int a,int b){


return b^(a^b)&-(a<b);

}
int Max(int a,int b){


return a^(a^b)&-(a<b);

}

int Min2(int a,int b){


return b+((a-b)&((a-b)>>31));

}
int Max2(int a,int b){


return a-((a-b)&((a-b)>>31));

}

int main(){

unsigned int a=3;
unsigned int b=2;

printf("\nMin : %d",Min2(a,b));
printf("\nMax : %d",Max2(a,b));


return 0;
}
