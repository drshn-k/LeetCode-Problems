//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
      string s="";
           if(S == 0 && N != 1){
               return "-1";
           }
           while(s.size() != N){
                if(S >= 9){
                    s = s+'9';
                    S = S-9;
                }
                else if(S > 0 && S < 9){
                    s = s + to_string(S);
                    S = 0;
                }
                else{
                    s = s + '0';
                }
           }
           if(S != 0){
               return "-1";
           }
           return s;   // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends