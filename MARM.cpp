#include <iostream>
using namespace std;
int main() {
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        long arr[100000];
        long k;cin>>k;
        for(int i=0;i<n;i++)
            cin>>arr[i];

        int N = (k/n)%3;
        int R = k%n;
        if(N==1)
        {
            for(int i=0;i<n/2;i++)
            {
                long a,b;a=arr[i];b=arr[n-1-i];
                arr[i] = a^b;
                arr[n-i-1] = a;
            }
            if(n%2)
                arr[n/2]=0;
        }

        else if(N==2)
        {
            for(int i=0;i<n/2;i++)
            {
                long a,b;a=arr[i];b=arr[n-1-i];
                arr[i] = b;
                arr[n-i-1] = a^b;
            }
            if(n%2)
                arr[n/2]=0;
        }
        else
        {
            if(n%2 && k>n)
                arr[n/2]=0;
        }


        for(int i=0;i<R;i++)
        {
            arr[i] = arr[i]^arr[n-i-1];
            cout<<arr[i]<<" ";
        }
        for(int i=R;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
