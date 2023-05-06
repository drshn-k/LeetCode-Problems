//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
       int solve(int cur,int cc,vector<int>coin,vector<vector<int>>&dp){
        if(dp[cc][cur]!=-1)return dp[cc][cur];
        if(cur==0&&cc==0)return 1;
        if(cc==0||cur==0)return 0;
        for(auto i:coin){
            if(cur-i>=0){
                if(solve(cur-i,cc-1,coin,dp))return dp[cc][cur]= 1;
            }
        }
        return dp[cc][cur]=0;
    }
    bool makeChanges(int n, int k, int target, vector<int> &coins) {
        vector<vector<int>>dp(k+1,vector<int>(target+1,-1));
        return solve(target,k,coins,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends