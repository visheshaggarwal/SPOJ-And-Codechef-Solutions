class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0,m=0;
        while(m<nums.size())
        {
            switch(nums[m])
            {
                case 0:
                    m++;
                    break;
                default:
                    swap(nums[l++],nums[m++]);
                    break;
            }
        }
    }
};
