class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int s=0,e=nums.size()-1;
        while(s<=e)
        {
            if(s==e)
                return nums[s];
            int mid = (s+e)/2;
            if(nums[mid]==nums[mid+1])
            {
                if(mid&1)
                    e = mid-1;
                else
                    s = mid + 2;
            }
            else if(nums[mid]==nums[mid-1])
            {
                if((e-mid)&1)
                    s = mid + 1;
                else
                    e = mid-2;
            }
            else
                return nums[mid];
        }
        return -1;
    }
};
