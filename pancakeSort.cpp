class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> v;
        for(int i=0;i<A.size();i++)
        {
            int min_idx = 0;
            for(int j=1;j<A.size()-i;j++)
            {
                if(A[min_idx] < A[j])
                    min_idx = j;
            }
            if(min_idx != A.size()-1-i)
            {
                v.push_back(min_idx+1);
                v.push_back(A.size()-1-i+1);
                for(int j=0;j<=min_idx/2;j++)
                    swap(A[j],A[min_idx-j]);
                for(int j=0;j<=(A.size()-1-i)/2;j++)
                    swap(A[j],A[A.size()-1-i-j]);
            }
        }
        return v;
    }
};
