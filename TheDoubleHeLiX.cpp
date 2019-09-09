#include <iostream>
#include<vector>
using namespace std;
int main() {
    int n,m;
    cin>>n;
    while(n!=0)
    {
        vector<int> v1;
        int a;
        for(int i=0;i<n;i++)
        {
            cin>>a;v1.push_back(a);
        }
        cin>>m;
        vector<int> v2;
        for(int i=0;i<m;i++)
        {
            cin>>a;v2.push_back(a);
        }
        int i=0,j=0;
        long s1=0,s2=0;
        while(i<n && j<m)
        {
            if(v1[i]<v2[j])
            {
                s1+=v1[i];
                i++;
            }
            else if(v2[j]<v1[i])
            {
                s2+=v2[j];
                j++;
            }
            else
            {
                s1+=v1[i];
                s2+=v2[j];
                s1 = max(s1,s2);
                s2=max(s2,s1);
                i++;j++;
            }
        }
        while(i<n)
        {
            s1+=v1[i];
            i++;
        }
        while(j<m)
        {
            s2+=v2[j];
            j++;
        }
        cout<<max(s1,s2)<<endl;
        cin>>n;
    }
}
