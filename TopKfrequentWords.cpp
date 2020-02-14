class Solution {
public:

    class comp
    {
        public:
        bool operator()(pair<int,string> a,pair<int,string> b)
    {
        if(a.first < b.first)
            return true;
        else if(a.first > b.first)
            return false;
        else{
            if(a.second < b.second)
                return false;
            else return true;
        }
    }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++)
        {
            if(m.find(words[i]) == m.end())
                m[words[i]]=1;
            else
                m[words[i]] += 1;
        }
        priority_queue<pair<int,string>, vector<pair<int,string> >,comp> pq;
        int cnt = 0;
        for(auto x:m)
        {
            if(cnt == k)
            {
                pq.push(make_pair(x.second,x.first));
                // pq.pop();
            }
            else
            {
                pq.push(make_pair(x.second,x.first));
                cnt++;
            }
        }

        vector<string> v;
        for(int i=0;i<k;i++)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};
