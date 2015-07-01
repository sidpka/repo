#include<stdio.h>
#include<conio.h>

void FindDFA(int dfa[][2],int k){

int i;
int state;
int trans0;
int trans1;

for(state=0;state<k;state++){

trans0=(state<<1);

dfa[state][0]=(trans0<k)?trans0:trans0-k;

trans1=(state<<1)+1;

dfa[state][1]=(trans1<k)?trans1:trans1-k;

}

}



void IsDivisible_Util(int dfa[][2],int n,int* state){

if(n!=0){

IsDivisible_Util(dfa,n>>1,state);
//printf("\nn i : %d",n);
(*state)=dfa[(*state)][n&1];

}


}

int IsDivisible(int n,int k){

int dfa[k][2];

FindDFA(dfa,k);

int i;
int j;

/*
for(i=0;i<k;i++){
for(j=0;j<2;j++){
printf("%d  ",dfa[i][j]);
}
printf("\n");
}
*/

int state=0;

IsDivisible_Util(dfa,n,&state);


return state==0;

}

int main(){

int n=47;
int k=5;

int result=IsDivisible(n,k);

if(result){
printf("\n%d is divisible by %d",n,k);
}else{
printf("\nNot divisible");
}



return 0;
}
