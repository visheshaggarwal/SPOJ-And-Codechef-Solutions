#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
long TopDown(int k,int i,vector<int> v,long dp[][1000])
{
    if(k<0)
        return INT_MAX;
    if(k==0)
        return 0;
    if(i>=v.size())
        return INT_MAX;
    int op1 = INT_MAX;
    int op2 = INT_MAX;

    if(dp[k][i]!=INT_MAX)
        return dp[k][i];


    //cout<<k<<"  "<<i<<endl;
    if(v[i]!=-1)
        op1 = TopDown(k-i-1,i,v,dp)+v[i];
    op2 = TopDown(k,i+1,v,dp);
    if(op1<0)
        dp[k][i] = op2;
    else if(op2<0)
        dp[k][i]=op1;
    else
        dp[k][i] = min(op1,op2);
    return dp[k][i];

}
int main()
{
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> v;
        for(int i=0;i<k;i++)
        {
            int j;cin>>j;
            v.push_back(j);
        }
        long dp[1000][1000]={0};
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<k;j++)
                dp[i][j]=INT_MAX;
        }
        long x = TopDown(k,0,v,dp);
        if(x<0 || x==INT_MAX)
            cout<<-1<<endl;
        else cout<<x<<endl;

    }
    return 0;
}
