#include <iostream>
using namespace std;
long mod = 1000000007;
long bottomUp(bool arr[][1000],int n,int m)
{
    long dp[1000][1000] = {0};
    for(int i=0;i<m;i++)
    {
        if(arr[0][i])
            break;
        dp[0][i] = 1;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][0])
            break;
        dp[i][0] = 1;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(!arr[i][j])
            {
                dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
            }
        }
    }

    return dp[n-1][m-1];
}
int main()
{
    int n,m,p;
    cin>>n>>m>>p;
    bool arr[1000][1000] = {false};
    for(int i=0;i<p;i++)
    {
        int x,y;cin>>x>>y;
        arr[x-1][y-1] = true;
    }

    cout<<bottomUp(arr,n,m);

}
