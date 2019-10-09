#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int n;cin>>n;
    while(n!=0)
    {
        int arr[100000];
        vector<int> pos,neg;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i] < 0)
            {
                neg.push_back(i);
            }
            else if(arr[i] > 0)
                pos.push_back(i);
        }

        long long i = 0,j = 0,work = 0;
        while(i < neg.size() && j < pos.size())
        {

            if(abs(arr[neg[i]]) > abs(arr[pos[j]]))
            {
                work += (abs(neg[i]-pos[j]))*arr[pos[j]];
                arr[neg[i]] = -1*abs(abs(arr[neg[i]]) - abs(arr[pos[j]]));
                j++;
            }
            else if(abs(arr[neg[i]]) < abs(arr[pos[j]]))
            {
                work += (abs(neg[i]-pos[j]))*abs(arr[neg[i]]);
                arr[pos[j]] = abs( arr[pos[j]] - -1*arr[neg[i]]);
                i++;
            }
            else
            {
                work += (abs(neg[i]-pos[j]))*abs(arr[pos[j]]);
                j++;
                i++;
            }
        }
        cout<<work<<endl;
        cin>>n;
    }
    return 0;
}
