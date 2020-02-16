class Solution {
public:
    void rec(vector<int> nums,vector<vector<int> > &v,int i)
    {
        if(i==nums.size())
        {
            v.push_back(nums);
            return;
        }

        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            rec(nums,v,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> >v;
        rec(nums,v,0);
        return v;
    }
};
