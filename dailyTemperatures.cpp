class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        vector<int> v;
        for(int i=0;i<T.size();i++)
            v.push_back(0);
        for(int i=0;i<T.size();i++)
        {
            while(!s.empty() && T[s.top()] < T[i])
            {
                v[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return v;
    }
};
