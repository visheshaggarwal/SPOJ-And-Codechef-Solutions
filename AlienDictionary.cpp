class Solution {
public:
    bool cycle = false;
    void dfs(unordered_map<char,vector<char> >g,unordered_map<char,bool> &visited,list<char> &l,char c,unordered_map<char,bool> top)
    {
        visited[c] = true;
        top[c] = true;

        for(auto x:g[c])
        {
            if(!visited[x]){
                dfs(g,visited,l,x,top);
            }
            else
            {
                if(top.find(x)!=top.end() && top[c])
                    cycle = true;
            }
        }
        l.push_front(c);
        top[c]=false;
    }
    string alienOrder(vector<string>& words) {
        unordered_map<char,vector<char> >g;
        unordered_map<char,bool> visited,top,all;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=0;j<min(words[i].length(),words[i+1].length());j++)
            {
                if(words[i][j] != words[i+1][j]){
                    g[words[i][j]].push_back(words[i+1][j]);
                    visited[words[i][j]]=false;
                    visited[words[i+1][j]]=false;
                    break;
                }
            }
        }
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                all[words[i][j]]=true;
            }
        }
        list<char> l;
        bool dfsCalled = false;
        for(auto x:g)
        {
            if(!visited[x.first]){
                dfsCalled = true;
                dfs(g,visited,l,x.first,top);
            }
        }
        string ans = "";
        if(cycle)
            return ans;
        for(auto x:l)
            ans += x;
        for(auto x:all)
        {
            if((visited.find(x.first)==visited.end() && dfsCalled) || g.size()==0)
                ans += x.first;
        }
        return ans;
    }
};
