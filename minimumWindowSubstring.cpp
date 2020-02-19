class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()==0 || t.length()==0 || t.length()>s.length())
            return "";
        unordered_map<char,int> m,tmp;
        for(int i=0;i<t.length();i++)
            m[t[i]]++;
        int i=0,j=0;
        int completed = 0;
        int ans = INT_MAX,sind = 0;

        while(j<s.length())
        {
            tmp[s[j]]++;
            if(m.find(s[j])!=m.end() && tmp[s[j]] == m[s[j]])
                completed++;

            while(i<=j && m.size()==completed)
            {
                if(ans > j-i+1)
                {
                    sind = i;
                    ans = j-i+1;
                }
                tmp[s[i]]--;
                if(m.find(s[i])!=m.end() && m[s[i]]>tmp[s[i]])
                    completed--;
                i++;
            }
            j++;
        }

        if(ans==INT_MAX)
            return "";
        else
        {
            return s.substr(sind,ans);
        }

    }
};
