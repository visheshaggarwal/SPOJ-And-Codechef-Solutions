class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int sidx = 0;
        int maxlen = 0,crlen=0;
        for(int i=0;i<s.length();i++)
        {
            cout<<maxlen<<" "<<crlen<<endl;
            if(m.find(s[i])==m.end())
            {
                crlen++;
                m[s[i]] = i;
            }
            else
            {
                maxlen = max(crlen,maxlen);
                if(sidx > m[s[i]]){
                    crlen++;
                }
                else
                {
                    crlen = i-m[s[i]];
                    sidx = m[s[i]]+1;
                }
                m[s[i]] = i;
            }
            // maxlen = max(crlen,i-m[s[i]]);
        }
                    cout<<maxlen<<" "<<crlen<<endl;

        return max(maxlen,crlen);
    }
};
