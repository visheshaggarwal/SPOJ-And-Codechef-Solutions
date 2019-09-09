#include <iostream>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;
long MinStops(pair<long,long> arr[],long d,long f,long n)
{
    long cnt=0;
    priority_queue<long> q;
    for(long i=0;i<=n;i++)
    {
        if(d-arr[i].first<=f)
        {
            f-= d-arr[i].first;
            q.push(arr[i].second);
            d = arr[i].first;
        }
        else
        {
            if(q.empty() && i!=0)
                return -1;
            if(i!=0)
            {
                while(f<d-arr[i].first)
                {
                    if(q.empty())
                        return -1;
                    //cout<<"fueled "<<q.top()<<endl;
                    f+=q.top();
                    cnt++;
                    q.pop();
                }
                f-=d-arr[i].first;
            }
            if(i!=0){
            q.push(arr[i].second);
            }
            else{
                cnt++;
                f+=arr[i].second;
            }
            d = arr[i].first;
        }
    }
    return cnt;
}
int main() {
    long t;cin>>t;
    while(t--)
    {
        long n;cin>>n;
        pair<long,long> arr[n+1];
        for(long i=0;i<n;i++)
        {
            cin>>arr[i].first>>arr[i].second;
        }
        arr[n].first=0;
        arr[n].second=0;
        long d,f;cin>>d>>f;
        sort(arr,arr+(n+1));
        for(long i=0;i<(n+1)/2;i++)
        {
            swap(arr[i],arr[n-i]);
        }
        if(d-arr[0].first>f)
        {
            cout<<-1<<endl;
            continue;
        }
        long ans = MinStops(arr,d,f,n);
        cout<<ans<<endl;
    }
}
