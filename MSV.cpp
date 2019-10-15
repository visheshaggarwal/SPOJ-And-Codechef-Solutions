#include <iostream>
#include<climits>
#include<unordered_map>
using namespace std;
int main() {
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[100000];
        long mp[1000000]={0};
        long maxv = INT_MIN;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            for(int j=1;j*j<=arr[i];j++)
            {
                if(arr[i]%j==0)
                {
                    mp[j-1] = mp[j-1] + 1;
                    if(j*j != arr[i])
                        mp[((arr[i])/(j)) - 1] = mp[((arr[i])/(j)) - 1] + 1;
                }
            }
            maxv = max(maxv,mp[arr[i]-1]);
        }
        if(maxv == 0)
            cout<<maxv<<endl;
        else
            cout<<maxv-1<<endl;


    }
}
