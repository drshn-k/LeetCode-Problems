//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void permute(vector<string>&v, int l, int r,string &s)
    {
        if(l==r)
        v.push_back(s);
        
        for(int i=l;i<=r;i++)
        {
            swap(s[l],s[i]);
            permute(v,l+1,r,s);
            swap(s[l],s[i]);
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string>v;
        int r=S.size()-1;
        int l=0;
        permute(v,l,r,S);
        
        sort(v.begin(),v.end());
        return v;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends