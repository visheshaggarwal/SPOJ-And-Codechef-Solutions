#include <iostream>
#include<algorithm>
using namespace std;
bool isPossible(int cook[],int n,int prata,int time)
{
    int num = 0;
    for(int i=0;i<n;i++)
    {
        int t = 0;
        int next_time = cook[i];
        while(t + next_time<=time)
        {
            num += 1;
            t += next_time;
            next_time += cook[i];
            if(num >= prata)
                return true;
        }
    }
    return false;
}
long minTimeNeeded(int cook[],int n,int prata)
{
    int s = 0;
    int e = cook[n-1]*prata*(prata+1)/2;
    int mid,ans = -1;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(isPossible(cook,n,prata,mid)){
            e = mid-1;
            ans = mid;
        }
        else
            s = mid + 1;
    }
    return ans;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int prata;cin>>prata;
        int cook[51];
        int n;cin>>n;
        for(int i=0;i<n;i++)
            cin>>cook[i];
        sort(cook,cook+n);
        cout<<minTimeNeeded(cook,n,prata)<<endl;
    }
}
