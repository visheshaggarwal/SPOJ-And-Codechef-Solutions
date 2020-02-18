#include <iostream>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    string s;cin>>s;
	    int c1=0,c2=0;
	    for(int i=0;i<s.length();i++)
	    {
	        if(i&1 && s[i]=='1')
	            c1++;
	       else if(i%2==0 && s[i]=='1')
	            c2++;

	    }
	    if((c1*2 + c2)%3==0)
	        cout<<1<<endl;
	   else
	        cout<<0<<endl;
	}
	return 0;
}
