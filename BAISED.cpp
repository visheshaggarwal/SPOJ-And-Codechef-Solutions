#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            string s;int a;
            cin>>s>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());

        long long badness = 0,actual_rank = 0;
        for(int i=0;i<n;i++)
        {
            actual_rank++;
            badness += abs(actual_rank-v[i]);
        }
        cout<<badness<<endl;
    }
}
