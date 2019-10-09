#include <iostream>
#include<algorithm>
using namespace std;
bool isPossible(long stall[],int n,int c,long Dist)
{
    int cow_count = 1;
    long last_placed = stall[0];
    for(int i=1;i<n;i++)
    {
        if(stall[i]-last_placed >= Dist)
        {
            cow_count++;
            last_placed = stall[i];
            if(cow_count >= c)
                return true;
        }
    }
    return false;
}
long minDistance(long stall[],int n,int c)
{
    long e = stall[n-1] - stall[0];
    long s = 0;
    long mid;
    long ans = -1;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(isPossible(stall,n,c,mid)){
            s = mid + 1;
            ans = mid;
        }
        else
            e = mid-1;
    }
    return ans;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        long stall[100001];
        int c;cin>>c;
        for(int i=0;i<n;i++)
            cin>>stall[i];
        sort(stall,stall+n);
        cout<<minDistance(stall,n,c)<<endl;
    }
}
