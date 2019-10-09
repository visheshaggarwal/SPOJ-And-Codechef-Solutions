#include <iostream>
#include<algorithm>
using namespace std;
bool isPossible(long tree_height[],long n,long m,long blade)
{
    long wood = 0;
    for(int i=0;i<n;i++)
    {
        if(tree_height[i] > blade)
        {
            wood += tree_height[i] - blade;
            if(wood >= m)
                return true;
        }
    }

    return false;
}

long maxHeight(long tree_height[],long n,long m)
{
    long s = 0;
    long e = -1;
    for(long i=0;i<n;i++)
        e = max(e,tree_height[i]);

    long mid,ans = 0;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(isPossible(tree_height,n,m,mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    long n,m;
    cin>>n>>m;
    long tree_height[1000000];
    for(long i=0;i<n;i++)
    {
        cin>>tree_height[i];
    }
    cout<<maxHeight(tree_height,n,m);
}
