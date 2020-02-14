class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> s;
        int ans = 0;
        for(int i=0;i<prices.size();i++)
        {
            if(s.empty())
                s.push(prices[i]);
            else
            {
                if(s.top() > prices[i])
                    s.push(prices[i]);
                else
                    ans = max(ans,prices[i]-s.top());
            }
        }
        return ans;
    }
};
