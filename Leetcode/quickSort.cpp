#include<iostream>
using namespace std;

int partition(int a[],int s,int e){

}

void quickSort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int p = partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}

int main(){

   return 0;
}
