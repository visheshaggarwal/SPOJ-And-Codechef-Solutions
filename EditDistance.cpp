#include<iostream>
using namespace std;
int minChanges(string a,string b)
{
    int dp[3001][3001];
    for(int i=0;i<=a.length();i++)
    {
        for(int j=0;j<=b.length();j++)
        {
            if(i==0)
                dp[0][j] = j;
            else if(j==0)
                dp[i][0] = i;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    return dp[a.length()][b.length()];
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        cout<<minChanges(a,b)<<endl;
    }
}
