class Solution {
public:
    string evaluate(string s,int i,int j)
    {
        if(i==j || s[i]==']')
            return "";

        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            return s[i]+evaluate(s,i+1,j);

        if(s[i]>='0' && s[i]<='9')
        {
            int m = 0,k=i;
            while(s[k]!='[')
            {
                m = m*10 + int(s[k]-'0');
                k++;
            }
            k++;
            int l = k,o=0,c=0;
            while(c!=o+1)
            {
                if(s[l]=='[')
                    o++;
                else if(s[l]==']')
                    c++;
                l++;
            }
            string a = evaluate(s,k,l-1);
            string b = "";
            for(int i=0;i<m;i++)
                b = b+a;
            return b+evaluate(s,l,j);
        }

        return "";

    }
    string decodeString(string s) {
        return evaluate(s,0,s.length());
    }
};
