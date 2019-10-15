#include <iostream>
using namespace std;
int main() {
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[1000];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            int minV = arr[i];
            int c = 0;
            for(int j=i-1;j>=i-5 && j>=0 ;j--)
            {
                if(minV < arr[j])
                    c++;
            }
            if(i>=5)
            {
                if(c==5)
                    cnt++;
            }
            if(i<5)
            {
                if(c==i)
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}
