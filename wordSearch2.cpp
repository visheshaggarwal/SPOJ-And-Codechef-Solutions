class Solution {
public:
    class Node
    {
        public:
            char c;
            unordered_map<char,Node*> m;
            bool ends;
            Node(char ch)
            {
                c = ch;
                ends = false;
            }
    };
    void insert(string s,Node* Trie,int i)
    {
        if(i==s.length()){
            Trie->ends = true;
            return;
        }
        if(Trie->m.find(s[i]) != Trie->m.end())
        {
            insert(s,Trie->m[s[i]],i+1);
        }
        else
        {
            Node* n = new Node(s[i]);
            Trie->m[s[i]] = n;
            insert(s,Trie->m[s[i]],i+1);
        }
    }
    void print(Node* Trie,string osf)
    {
        osf += Trie->c;
        if(Trie->ends)
            cout<<osf<<endl;
        for(auto x : Trie->m){
            print(x.second,osf);
        }
    }
    void rec(Node* Trie,vector<vector<char>>& board,int visited[][1000],int i,int j,int m,int n,unordered_map<string,int> &done,string s)
    {
        visited[i][j] = 1;
        if(Trie->ends)
            done[s] = 1;
        if(i-1 >= 0 && Trie->m.find(board[i-1][j])!=Trie->m.end() && visited[i-1][j]==0)
            rec(Trie->m[board[i-1][j]],board,visited,i-1,j,m,n,done,s+board[i-1][j]);
        if(j-1 >= 0 && Trie->m.find(board[i][j-1])!=Trie->m.end() && visited[i][j-1]==0)
            rec(Trie->m[board[i][j-1]],board,visited,i,j-1,m,n,done,s+board[i][j-1]);

        if(i+1 < m && Trie->m.find(board[i+1][j])!=Trie->m.end() && visited[i+1][j]==0)
            rec(Trie->m[board[i+1][j]],board,visited,i+1,j,m,n,done,s+board[i+1][j]);
        if(j+1 <n && Trie->m.find(board[i][j+1])!=Trie->m.end() && visited[i][j+1]==0)
            rec(Trie->m[board[i][j+1]],board,visited,i,j+1,m,n,done,s+board[i][j+1]);
        visited[i][j] = 0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* Trie = new Node('\0');
        vector<string> v;
        if(board.size()==0 || words.size()==0)
            return v;
        for(int i=0;i<words.size();i++)
        {
            insert(words[i],Trie,0);
        }
        unordered_map<string,int> done;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                int m,n;
                m=board.size();
                n = board[0].size();
                int visited[m][1000] = {0};
                string a = "";
                if(Trie->m.find(board[i][j])!=Trie->m.end())
                    rec(Trie->m[board[i][j]],board,visited,i,j,m,n,done,a+board[i][j]);

            }
        }
        for(auto x : done)
            v.push_back(x.first);
        for(auto x : Trie->m)
            print(x.second,"");
        return v;
    }
};
