//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
     
         int ans=0;
     
        unordered_map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        
        for(int i=0;i<str.length();i++){
            if(mp[str[i]]<mp[str[i+1]]&&i<str.length()-1){
                ans-=mp[str[i]];
            }
            else{
                ans+=mp[str[i]];
            }
        }
        return ans;
   // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends