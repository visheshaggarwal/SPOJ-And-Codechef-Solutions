class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int> >v;
        if(intervals.size()==0)
            return v;
        v.push_back(intervals[0]);
        int i=1,j=0;
        for(;i<intervals.size();i++)
        {
            if(intervals[i][0] >= v[j][0] && intervals[i][0]<= v[j][1])
            {
                v[j][1] = max(v[j][1],intervals[i][1]);
            }
            else
            {
                j++;
                v.push_back(intervals[i]);
            }
        }
        return v;
    }
};
