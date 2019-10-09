#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<pair<int,int> > V;
        for(int i=0;i<n;i++)
        {
            int s,e;cin>>s>>e;
            V.push_back(make_pair(e,s));
        }
        sort(V.begin(),V.end());

        int activites_done = 0;
        int endtime = 0;
        for(int i=0;i<n;i++)
        {
            if(endtime <= V[i].second)
            {
                activites_done += 1;
                endtime = V[i].first;
            }
        }
        cout<<activites_done<<endl;
    }
}
