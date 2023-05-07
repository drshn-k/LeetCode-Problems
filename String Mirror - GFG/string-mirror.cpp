//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
   string s;
       int i=0;
       s=s+str[0];
       while(i<str.length()-1&&((i>0&&str[i]>=str[i+1])||(i==0&&str[i]>str[i+1])))
       {
           s=s+str[i+1];
           i++;
       }
    string ans=s;
    reverse(s.begin(),s.end());
    ans=ans+s;
    return ans;    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends