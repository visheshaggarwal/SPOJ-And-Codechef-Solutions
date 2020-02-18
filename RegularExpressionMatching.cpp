class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[1000][1000] = {false};
        dp[0][0] = true;
        dp[0][1] = false;
        for(int i=1;i<p.length();i++){
            if(p[i]=='*')
                dp[0][i+1] = dp[0][i-1];
        }
        for(int i=1;i<=s.length();i++)
            dp[i][0] = false;
        for(int i=1;i<=s.length();i++)
        {
            for(int j=1;j<=p.length();j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='.')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i][j-2];
                    if((s[i-1]==p[j-2] || p[j-2]=='.') && !dp[i][j])
                        dp[i][j] = dp[i-1][j];
                }
                else
                    dp[i][j] = false;
            }
        }

        return dp[s.length()][p.length()];
    }
};
