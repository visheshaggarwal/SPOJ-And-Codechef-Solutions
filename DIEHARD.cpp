#include<iostream>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int h,a,ans;
        cin>>h>>a;

        ans=1; h=h+3; a=a+2;
        while(true)
        {
            if(h>20&&a<=10){
                h = h-17;
                a=a+7;
                ans=ans+2;
            }

            else if(h>5&&a>10){
                h = h-2;
                a=a-8;
                ans=ans+2;
            }

            else
            {
                cout<<ans<<endl;
                break;
            }
        }
    }
    return 0;
}
