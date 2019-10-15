#include <iostream>
using namespace std;
int main() {
    int t;cin>>t;
    while(t--)
    {
        long n,m,q;
        cin>>n>>m>>q;
        long r[100000]={0};
        long c[100000]={0};
        for(long i=0;i<q;i++)
        {
            long a,b;cin>>a>>b;
            r[a-1]++;
            c[b-1]++;
        }
        long cnt1=0,cnt2=0;
        for(long i=0;i<n;i++)
        {
            if(r[i]%2==0)
                cnt1++;
        }
        for(long i=0;i<m;i++)
        {
            if(c[i]%2==0)
                cnt2++;
        }
        long long ans = (n*m - cnt1*cnt2 - (n-cnt1)*(m-cnt2));
        cout<<ans<<endl;
    }
}
