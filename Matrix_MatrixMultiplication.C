#include<stdio.h>
#include<conio.h>





int main(){

int a[2][3]={{1,2,3},{4,5,6}};

int b[3][3]={{7,8,9},{10,11,12},{13,14,15}};

int m=2;
int n=3;
int p=3;

int i;
int j;
int k;

int c[m][p];

for(i=0;i<m;i++){
for(j=0;j<p;j++){
c[i][j]=0;

for(k=0;k<n;k++){
c[i][j]+=a[i][k]*b[k][j];
}

}

}


printf("\nArra\n\n");

for(i=0;i<m;i++){
for(j=0;j<p;j++){
printf("%d  ",c[i][j]);
}
printf("\n");
}



return 0;
}
