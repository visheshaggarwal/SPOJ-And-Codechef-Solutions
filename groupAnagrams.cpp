class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> >m;
        for(int i=0;i<strs.size();i++)
        {
            string a = strs[i];
            sort(a.begin(),a.end());
            m[a].push_back(strs[i]);
        }
        vector<vector<string> >v;
        for(auto x : m)
        {
            v.push_back(x.second);
        }
        return v;
    }
};
