#include<stdio.h>
#include<conio.h>
#include<string.h>


void FindMaxLenSubstring(char str[],int K){

int n=strlen(str);

int i;
int j;
int curLen;
int maxLen=0;
int start;
int leftK;

for(i=0;i<n;i++){
leftK=K;
curLen=0;
int visited[26]={0};
for(j=i;j<n;j++){
if(visited[str[j]-'a']==0 && leftK){
leftK--;
visited[str[j]-'a']=1;
curLen++;
}else if(visited[str[j]-'a']==1){
curLen++;
}else if(visited[str[j]-'a']==0 && leftK==0){

break;

}
}

if(maxLen<curLen){
maxLen=curLen;
start=i;
}

}

printf("\nMax length of substring with %d unique characters : %d",K,maxLen);
printf("\nAnd substring is : ");
for(i=start;i<start+maxLen;i++){
printf("%c",str[i]);
}


}

int IsValidAdd(int count[],int K){

int i;
int u=0;

for(i=0;i<26;i++){
if(count[i]>0){
u++;
}
}

return K>=u;



}


void FindMaxLenSubstring2(char str[],int K){

int n=strlen(str);

int count[26]={0};

int start=0;
int end=0;

int maxLen=0;
int u=0;
int i;
for(i=0;i<n;i++){
    if(count[str[i]-'a']==0){
    u++;
    }
count[str[i]-'a']++;
}

int maxStart=0;

if(u<K){
printf("\nNo of unique characters is lesser than required");
return;
}

for(i=0;i<26;i++){
count[i]=0;
}



count[str[0]-'a']++;

for(i=1;i<n;i++){

count[str[i]-'a']++;
end++;

if(!IsValidAdd(count,K)){
count[str[start]-'a']--;
start++;
}

if(maxLen<end-start+1){
maxLen=end-start+1;
maxStart=start;
}

}

printf("\nMax len substring with : %d unique char : %d ",K,maxLen);

printf("\nMaxLen substring :  ");

for(i=maxStart;i<maxStart+maxLen;i++){
printf("%c",str[i]);
}


}

int main(){

char str[]="aabbcc";
int K=2;
//FindMaxLenSubstring(str,K);

FindMaxLenSubstring2(str,K);



return 0;
}
