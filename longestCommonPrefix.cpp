class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string a = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            string b = "";
            for(int j=0;j<min(a.length(),strs[i].length());j++)
            {
                if(a[j]==strs[i][j])
                    b += a[j];
                else
                    break;
            }
            a = b;
        }
        return a;
    }
};
