#include<stdio.h>
#include<conio.h>


int FindSmallestMissingNumber(int* arr,int n){
int i;
if(arr[0]!=0){
return 0;
}
for(i=0;i<n-1;i++){
if(arr[i+1]!=arr[i]+1){
return arr[i]+1;
}
}
return -1;
}

int BinarySearch(int* arr,int low,int high){

if(high>=low){
int mid=(low+high)/2;

int leftElm;
int rightElm;
int midElm=-1;
leftElm=BinarySearch(arr,low,mid-1);

if(mid>low && arr[mid-1]+1!=arr[mid]){
midElm=arr[mid-1]+1;
}else if(midElm==-1 && mid<high && arr[mid]+1!=arr[mid+1]){
midElm=arr[mid]+1;
}

rightElm=BinarySearch(arr,mid+1,high);

if(leftElm!=-1){
return leftElm;
}else if(midElm!=-1){
return midElm;
}else{
return rightElm;
}

}

return -1;
}

int FindSmallestMissingNumber2(int* arr,int n){

if(arr[0]!=0){
return 0;
}

int elm=BinarySearch(arr,0,n-1);
if(elm==-1){
return -1;
}else{
return elm;
}

}

int BS(int* arr,int low,int high){

if(low>high){
return high+1;
}

if(low!=arr[low]){
return low;
}

int mid=(low+high)/2;

if(arr[mid]>mid){
return BS(arr,low,mid);
}else{
return BS(arr,mid+1,high);
}

}

int FindSmallestMissingNumber3(int* arr,int n){

return BS(arr,0,n-1);
}

int main(){

int arr[]={0,1,2,5,7,9};

int n=sizeof(arr)/sizeof(arr[0]);

/* O(n) time complexity
int smallestMissingNUmber=FindSmallestMissingNumber(arr,n);
*/

/*O(Log(n))
int smallestMissingNUmber=FindSmallestMissingNumber2(arr,n);
*/
//Another O(Log(n))
int smallestMissingNUmber=FindSmallestMissingNumber3(arr,n);
if(smallestMissingNUmber!=-1){
printf("\nSmallest Missing number : %d",smallestMissingNUmber);
}else{
printf("\nNo missing number");
}


return 0;
}
