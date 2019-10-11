#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int LongestIncresingSubsequence(vector<int> v)
{
    int *lis = new int[v.size()];
    int ans = 0;
    int n = v.size();

    for(int i=0;i<n;i++)
    {
        lis[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(v[j] <= v[i] && lis[j]+1 > lis[i]){
                lis[i] = lis[j] + 1;
            }
        }
        ans = max(ans,lis[i]);
    }
    return ans;
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int xOnLeftSide[1000],xOnRightSide[1000];
        for(int i=0;i<n;i++)
            cin>>xOnLeftSide[i];
        for(int i=0;i<n;i++)
            cin>>xOnRightSide[i];
        pair<int,int> X[1000];
        for(int i=0;i<n;i++)
        {
            X[i] = make_pair(xOnLeftSide[i],xOnRightSide[i]);
        }
        sort(X,X+n);
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(X[i].second);
        }
        cout<<LongestIncresingSubsequence(v)<<endl;

    }

}
