class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int ans = 0;
        for(int i=0;i<height.size();i++)
        {
            while(!s.empty() && height[s.top()]<= height[i])
            {
                int top = s.top();
                s.pop();
                if(!s.empty())
                    ans += (i-s.top()-1)*(min(height[s.top()],height[i]) - height[top]);
            }
            s.push(i);
        }
        return ans;
    }
};
