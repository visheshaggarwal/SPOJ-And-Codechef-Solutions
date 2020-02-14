class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        int*arr = new int[n];
        for(int i=0;i<n;i++)
            arr[i]=0;
        unordered_map<int,vector<int> > m;
        for(int i=0;i<prerequisites.size();i++)
        {
            arr[prerequisites[i][0]]+=1;
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
                q.push(i);
        }

        while(!q.empty())
        {
            n--;
            for(auto x:m[q.front()])
            {
                arr[x]--;
                if(arr[x]==0)
                    q.push(x);
            }
            q.pop();
        }
        return n==0;

    }
};
