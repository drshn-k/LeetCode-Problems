//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    //whether j is prime or not
    bool isPrime(int j){
        if (j < 2) {
        return false;
    }
        for(int i=2;i<=sqrt(j);i++){
            if(j%i==0)
              return false;
        }
        return true;
    }
    
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int>ans;
       
        
        ans.push_back(0);
        ans.push_back(1);
        
        for(int i=2;i<=n;i++){
            int least=n;
            for(int j=2;j<=i;j++){
                if(i%j==0 && isPrime(j)){
                    least=j;
                    break;
                }
                
            }
            ans.push_back(least);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends