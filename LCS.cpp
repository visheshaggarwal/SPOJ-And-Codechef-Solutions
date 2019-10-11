#include <iostream>
using namespace std;

int LCS(string a,string b)
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
    cout<<"Longest Common Subsequence is "<<lcs<<endl;
    return dp[a.size()][b.size()];
}

int main()
{
   string str1,str2;
   cin>>str1>>str2;

   cout<<LCS(str1,str2);
}
