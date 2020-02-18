class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        int c = 0;
        m[0].push_back(-1);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                c++;
            else
                c--;
            if(m.find(c)==m.end())
                m[c].push_back(i);
            else
            {
                if(m[c].size()==1)
                    m[c].push_back(i);
                else
                    m[c][1]=i;
            }
        }
        int ans = 0;
        for(auto x : m)
        {
            if(x.second.size()==2)
                ans = max(ans,x.second[1]-x.second[0]);
        }
        return ans;
    }
};
