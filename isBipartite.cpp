class Solution {
public:
    void dfs(vector<vector<int>>& graph,unordered_map<int,bool> &visited,bool &ans,bool clr,int i)
    {
        visited[i] = clr;
        for(int j=0;j<graph[i].size();j++)
        {
            if(visited.find(graph[i][j])==visited.end())
                dfs(graph,visited,ans,!clr,graph[i][j]);
            else
            {
                if(clr == visited[graph[i][j]])
                    ans = false;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,bool> visited;
        bool ans = true;
        for(int i=0;i<graph.size();i++)
        {
            if(visited.find(i)==visited.end())
                dfs(graph,visited,ans,true,i);
        }
        return ans;
    }
};
