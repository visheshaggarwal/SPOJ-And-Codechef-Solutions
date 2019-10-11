#include <iostream>
#include<algorithm>
using namespace std;
string combine(string a,string b)
{
    int dp[a.size()+1][b.size()+1] = {0};

    for(int i=0;i<=a.size();i++)
    {
        for(int j=0;j<=b.size();j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    string lcs = "";
    int i=a.size(),j=b.size();
    while(i>0 && j>0)
    {
        if(a[i-1] == b[j-1])
        {
            lcs = a[i-1] + lcs;
            i--;
            j--;
        }
        else if(dp[i][j] == dp[i-1][j])
        {
            i--;
        }
        else if(dp[i][j] == dp[i][j-1])
        {
            j--;
        }
    }

    string newFruit = "";
    i=a.size()-1,j=b.size()-1;
    int k = 0;
    k = lcs.size()-1;

    while(k>=0)
    {
        while(i>=0 && a[i]!=lcs[k])
        {
            newFruit += a[i];
            i--;
        }
        while(j>=0 && b[j]!=lcs[k])
        {
            newFruit += b[j];
            j--;
        }
        newFruit += lcs[k];
        k--;
        j--;
        i--;
    }

    while(i>=0)
    {
        newFruit += a[i];
        i--;
    }
    while(j>=0)
    {
        newFruit += b[j];
        j--;
    }

    reverse(newFruit.begin(),newFruit.end());
    return newFruit;
}

int main() {
    string a,b;
    while (cin>>a && cin>>b ) {
       cout<<combine(a,b)<<endl;
    }
}
