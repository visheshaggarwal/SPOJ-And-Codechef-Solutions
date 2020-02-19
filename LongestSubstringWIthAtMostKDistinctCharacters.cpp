class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int i = 0,j=0;
        int ans = 0;
        unordered_map<char,int> m;
        while(j<s.length())
        {
            m[s[j]]+=1;
            if(m.size()<=k)
            {
                ans = max(ans,j-i+1);
                j++;
            }
            else
            {
                while(m.size()>k)
                {
                    m[s[i]]--;
                    if(m[s[i]] == 0)
                        m.erase(s[i]);
                    i++;
                }
                ans = max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
};
