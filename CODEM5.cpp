#include <iostream>
#include<climits>
using namespace std;
int MinRequired(int arr[],int i,int w,int n,int count)
{
    if(w==0)
        return count;
    if(i==n)
        return INT_MAX;
    int op1 = INT_MAX;
    if(arr[i]<=w)
        op1 = MinRequired(arr,i+1,w-arr[i],n,count+1);
    int op2 = MinRequired(arr,i+1,w,n,count);
    return min(op1,op2);
}
int main() {
    int t;cin>>t;
    while(t--)
    {
        int n,w;cin>>n>>w;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int ans = MinRequired(arr,0,w,n,0);
        if(ans==INT_MAX)
            cout<<"impossible"<<endl;
        else
            cout<<ans<<endl;
    }
}
