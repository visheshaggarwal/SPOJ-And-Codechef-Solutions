class Solution {
public:
    void rec(int n,vector<string> &v,string osf,int o,int e)
    {
        if(o==e && o==n)
        {
            v.push_back(osf);
            return;
        }
        if(o<n)
            rec(n,v,osf+'(',o+1,e);
        if(o>e)
            rec(n,v,osf+')',o,e+1);

    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        rec(n,v,"",0,0);
        return v;
    }
};
