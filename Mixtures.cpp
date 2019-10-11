#include <iostream>
#include<climits>
using namespace std;
long sum(int mixtures[],int s,int e)
{
    long ans = 0;
    for(int i=s;i<=e;i++)
    {
        ans += mixtures[i]%100;
        ans %= 100;
    }
    return ans;
}
long minSmoke(int mixtures[],long dp[][1000],int s,int e)
{
    if(s>=e)
        return 0;

    if(dp[s][e]!=-1)
        return dp[s][e];

    dp[s][e] = INT_MAX;
    for(int i=s;i<=e;i++)
    {
        dp[s][e] = min(dp[s][e],minSmoke(mixtures,dp,s,i)+minSmoke(mixtures,dp,i+1,e)+sum(mixtures,s,i)*sum(mixtures,i+1,e));
    }

    return dp[s][e];
}
int main() {
    int n;

    while(cin>>n)
    {
        int mixtures[1000];
        long dp[1000][1000];
        for(int i=0;i<n;i++)
            cin>>mixtures[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                dp[i][j]= -1;
        }

        cout<<minSmoke(mixtures,dp,0,n-1)<<endl;
    }
}
