#include<iostream>
using namespace std;

void px(int*a,int l,int r){
    if(l<r){
        int p=a[(l+r)/2],i=l,j=r,t;
        while(i<=j){
            while(a[i]<p)i++;
            while(a[j]>p)j--;
            if(i<=j)t=a[i],a[i++]=a[j],a[j--]=t;
        }
        px(a,l,j);px(a,i,r);
    }
}
int main(){
    int n,a[1000],i=0;
    cin>>n;
    while(i<n){
        cin>>a[i++];
    }
    px(a,0,n-1);
    for(i=0;i<n;){
        cout<<a[i]<<(++i<n?" ":"");
        }
    return 0;
}