class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i]) != m.end())
                continue;
            if(m.find(nums[i]+1)!=m.end() && m.find(nums[i]-1)!=m.end())
            {
                ans = max(ans,m[nums[i]+1]+m[nums[i]-1]+1);
                int l = m[nums[i]+1]+m[nums[i]-1]+1;
                m[nums[i]+m[nums[i]+1]] = l;
                m[nums[i]-m[nums[i]-1]] = l;
                m[nums[i]] = l;
            }
            else if(m.find(nums[i]+1)==m.end() && m.find(nums[i]-1)!=m.end())
            {
                ans = max(ans,m[nums[i]-1]+1);
                m[nums[i]] = m[nums[i]-1]+1;
                m[nums[i] - m[nums[i]-1]]+=1;
            }
            else if(m.find(nums[i]+1)!=m.end() && m.find(nums[i]-1)==m.end())
            {
                ans = max(ans,m[nums[i]+1]+1);
                m[nums[i]] = m[nums[i]+1]+1;
                m[nums[i] + m[nums[i]+1]]+=1;
            }
            else
            {
                m[nums[i]] = 1;
                ans = max(ans,1);
            }
        }
        return ans;
    }
};
