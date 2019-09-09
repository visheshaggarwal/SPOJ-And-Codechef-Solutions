#include <iostream>
using namespace std;
unsigned long long numOfCodes(string str)
{
    unsigned long long dp[str.length()]={0};
    dp[0]=1;
    if((str[0]-'0')*10 + (str[1]-'0')>=1 && (str[0]-'0')*10 + (str[1]-'0')<=26)
        dp[1]=2;
    else
        dp[1]=1;
    if(str[1]=='0' && dp[1]==2)
        dp[1]=1;

    for(int i=2;i<str.length();i++)
    {
        if((str[i-1]-'0')*10 + (str[i]-'0')>=10 && (str[i-1]-'0')*10 + (str[i]-'0')<=26)
            dp[i] = dp[i-2];
        if(str[i]!='0')
            dp[i] += dp[i-1];
    }
    return dp[str.length()-1];
}
int main() {
    string s;cin>>s;
    while(s!="0")
    {
        cout<<numOfCodes(s)<<endl;
        cin>>s;
    }
    return 0;
}
