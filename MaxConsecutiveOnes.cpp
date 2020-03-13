class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i=0,j=0,cnt=0;
        int ans = -1;
        while(i<A.size())
        {
            if(A[i]){
                ans = max(ans,i-j+1);
                i++;
            }
            else
            {
                if(cnt<K){
                    cnt++;
                    ans = max(ans,i-j+1);
                    i++;
                }
                else
                {
                    while(j<=i && A[j]!=0)
                        j++;
                    if(j==A.size()){
                        ans = max(ans,i-j+1);
                        return ans;
                    }
                    j++;
                    ans = max(ans,i-j+1);
                    i++;
                }
            }
        }
        ans = max(ans,i-j);
        return ans;
    }
};
