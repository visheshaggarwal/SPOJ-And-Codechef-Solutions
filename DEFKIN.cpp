#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int l,b,n;
        cin>>l>>b>>n;
        if(n==0)
        {
            cout<<l*b<<endl;
            continue;
        }
        vector<int> X_arr,Y_arr;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            X_arr.push_back(x);
            Y_arr.push_back(y);
        }
        sort(X_arr.begin(),X_arr.end());
        sort(Y_arr.begin(),Y_arr.end());

        int max_x=X_arr[0]-1,max_y=Y_arr[0]-1;
        for(int i=1;i<n;i++)
        {
            max_x = max(max_x,X_arr[i]-X_arr[i-1]-1);
            max_y = max(max_y,Y_arr[i]-Y_arr[i-1]-1);
        }

        max_x = max(max_x,l - X_arr[n-1]);
        max_y = max(max_y,b - Y_arr[n-1]);

        cout<<max_x*max_y<<endl;
    }
}
