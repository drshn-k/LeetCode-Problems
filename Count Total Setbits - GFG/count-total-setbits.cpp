//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  long long count(long long n) {
        int count = 0;
        
        while(n) {
            int digit = n % 2;
            if(digit) count++;
            n /= 2;
        }
        
        return count;
    }
  
    long long countBits(long long N) {
        // Solution 1 -> TLE
     
        
        // Solution 3 -> Even Odd also accepted
        vector<int> temp(N + 1);
        int cnt = 0;
        
        for(int i = 1; i <= N; i++) {
            temp[i] = (i % 2 == 0) ? temp[i / 2] : temp[i / 2] + 1;
            cnt += temp[i];
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends