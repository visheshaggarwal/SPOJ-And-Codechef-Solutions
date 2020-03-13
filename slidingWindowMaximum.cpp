class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<pair<int,int> >l;
        vector<int> v;
        if(k==1)
            return nums;
        for(int i=0;i<k;i++)
        {
            if(l.size()==0)
                l.push_back(make_pair(nums[i],0));
            else
            {
                while(l.size()>0 && l.back().first <= nums[i])
                    l.pop_back();
                l.push_back(make_pair(nums[i],i));
            }

            if(i==k-1)
                v.push_back(l.front().first);
        }
        for(int i=k;i<nums.size();i++)
        {
            if(i-k == l.front().second)
                l.pop_front();
            if(l.size()==0)
                l.push_back(make_pair(nums[i],i));
            else{
                while(l.size()>0 && l.back().first <= nums[i])
                    l.pop_back();
                l.push_back(make_pair(nums[i],i));
            }

            v.push_back(l.front().first);
        }
        return v;
    }
};
