int a[26] = {0};
bool cmp(char a1,char a2)
{
    return a[a1-'a'] < a[a2-'a'];
}
class Solution {
public:

    string customSortString(string S, string T) {
        for(int i=0;i<26;i++)
        {
            a[i]=0;
        }
        for(int i=0;i<S.length();i++)
        {
            if(a[S[i]-'a']==0)
                a[S[i]-'a'] = i;
        }
        for(int i=0;i<26;i++)
        {
            if(a[i]==0 && char(i+'a')!=S[0])
                a[i] = S.length();
        }

        int n = T.length();
        sort(T.begin(),T.end(),cmp);
        return T;
    }
};
