#include <iostream>
using namespace std;
int main()
{
    long long *dp = new long long[20000001];
    dp[1] = 0;
    for(int i=2;i<20000001;i++)
    {
        dp[i] = 1 + dp[i-1];
        if(i%2==0)
        {
            dp[i] = min(dp[i],dp[i/2]+1);
        }
        if(i%3==0)
        {
            dp[i] = min(dp[i],dp[i/3]+1);
        }
    }
    int t,i=1;cin>>t;
    while(i<=t)
    {
        long n;cin>>n;
        cout<<"Case "<<i<<": "<<dp[n]<<endl;
        i+=1;
    }

}
