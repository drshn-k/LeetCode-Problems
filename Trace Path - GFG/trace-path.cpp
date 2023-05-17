//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
              int mnn=1,mxn=1,mnm=1,mxm=1;
        int x=1,y=1;
        for(auto i:s){
            if(i=='L')y--;
            else if(i=='R')y++;
            else if(i=='U')x++;
            else if(i=='D')x--;
            mnn=min(x,mnn);
            mxn=max(x,mxn);
            mnm=min(y,mnm);
            mxm=max(y,mxm);
        }
        return (abs(mxn-mnn)<n)&&(abs(mxm-mnm)<m);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends