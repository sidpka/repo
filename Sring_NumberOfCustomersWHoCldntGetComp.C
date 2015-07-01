#include<stdio.h>
#include<conio.h>
#include<string.h>


int FindUnservedCustomers(char str[],int n){

int countUnserved=0;

int visited[26];

int i;

for(i=0;i<26;i++){
visited[i]=0;
}

int availableComp=n;
int len=strlen(str);

for(i=0;i<len;i++){
if(visited[str[i]-'A']==0 && availableComp){
visited[ str[i]-'A' ]=1;
availableComp--;
}else if(visited[str[i]-'A']){
availableComp++;
}
else if(visited[str[i]-'A']==0 && availableComp==0){
countUnserved++;
visited[str[i]-'A']=1;
}
}


return countUnserved;
}

int main(){

int n=3;
char str[]="GACCBDDBAGEE";

int result=FindUnservedCustomers(str,n);

printf("\nNumber of customers who couldn't be served : %d",result);



return 0;
}
