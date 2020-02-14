class Solution {
public:
    string longestPalindrome(string s) {
        if(s=="")
            return s;
        bool dp[s.length()][s.length()]={false};
        for(int i=0;i<s.length();i++)
            dp[i][i] = true;
        int maxlen = 1;
        int st=0,en=0;
        for (int i = 0; i < s.length()-1; ++i)
        {
            if (s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                st = i;
                en = i+1;
                maxlen = 2;
            }
        }

        for (int k = 3; k <= s.length(); ++k)
        {
            for (int i = 0; i < s.length()-k+1 ; ++i)
            {
                int j = i + k - 1;

                if (dp[i+1][j-1] && s[i] == s[j])
                {
                    dp[i][j] = true;

                    if (k > maxlen)
                    {
                        st = i;
                        en = j;
                        maxlen = k;
                    }
                }
            }
        }
        string ans = "";
        for(int i=st;i<=en;i++)
            ans += s[i];
        return ans;
    }
};
