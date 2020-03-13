class Solution {
public:
    int Rec(vector<string> arr,int i,string osf)
    {
        if(i==arr.size())
        {
            int tmp[26] = {0};
            if(osf.length()>26)
                return 0;
            for(int j=0;j<osf.length();j++)
            {
                if(tmp[osf[j]-'a']==1)
                    return 0;
                tmp[osf[j]-'a']++;
            }
            return osf.length();
        }

        int op1 = 0,op2=0;

        if(osf.length()+arr[i].length() <=26)
            op1 = Rec(arr,i+1,osf+arr[i]);
        op2 = Rec(arr,i+1,osf);
        return max(op1,op2);
    }
    int maxLength(vector<string>& arr) {
        return Rec(arr,0,"");
    }
};
