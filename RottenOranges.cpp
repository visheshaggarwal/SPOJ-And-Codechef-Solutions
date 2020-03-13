#include <iostream>
#include<unordered_map>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
void assign(unordered_map<long,vector<long> >&g,int a,int b,int i,int j,int k,int l)
{
    if(a==2 && b==1)
        g[i*100 + j].push_back(k*100 + l);
    if(a==1 && b==1)
        g[i*100 + j].push_back(k*100 + l);
}
int main() {
	int t,r,c;
	cin>>t;
	while(t--)
	{
	    cin>>r>>c;
	    int **arr = new int*[r];
	    for(int i=0;i<r;i++)
	        arr[i] = new int[c];
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	            cin>>arr[i][j];
	    }
	    unordered_map<long,vector<long> >g;
	    unordered_map<long,long> d;
	    queue<long> q;
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            d[i*100 + j] = INT_MAX;
	            int a = arr[i][j];
	            if(a==2){
	                q.push(i*100 + j);
	                d[i*100 + j] = 0;
	            }
	            if(i-1 >= 0)
	                assign(g,a,arr[i-1][j],i,j,i-1,j);
	            if(i+1 < r)
	                assign(g,a,arr[i+1][j],i,j,i+1,j);
	            if(j-1 >= 0)
	                assign(g,a,arr[i][j-1],i,j,i,j-1);
	            if(j+1 < c)
	                assign(g,a,arr[i][j+1],i,j,i,j+1);
	        }
	    }

	    while(!q.empty())
	    {
	        long u = q.front();
	        q.pop();
	        for(auto x : g[u])
	        {
	            if(d[x] > d[u] + 1)
	            {
	                d[x] = d[u] + 1;
	                q.push(x);
	            }
	        }
	    }
	    long finans = INT_MIN;
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            if(arr[i][j]!= 0)
	                finans = max(finans,d[i*100 + j]);
	        }
	    }
	    if(finans == INT_MAX)
	        cout<<-1<<endl;
	    else
	        cout<<finans<<endl;

	    for(int i=0;i<r;i++)
	        delete []arr[i];
	    delete []arr;
	}
	return 0;
}
