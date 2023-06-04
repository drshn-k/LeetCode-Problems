//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {string ans = ""; for(int i = 0; i < s.size(); i++) { string temp = ""; while(i < s.size() && s[i] >= '0' && s[i] <= '9') { temp += s[i++]; } ans = temp + ans; if(i < s.size()) { ans = s[i] + ans; } } return ans;
            //code here.
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends