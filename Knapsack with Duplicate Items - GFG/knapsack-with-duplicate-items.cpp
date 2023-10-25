//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
         int dp[N + 1][W + 1];
    
    // Initialize the 'dp' array with zeros.
    memset(dp, 0, sizeof(dp));

    // Initialize the first row and first column of the 'dp' array to zeros.
    // This represents the case when there are no items or no weight capacity available.
    for (int i = 0; i <= W; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 0;
    }

    // Fill the 'dp' array by considering all possible items and weight capacities.
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            // Check if the weight of the current item is less than or equal to the current capacity 'j'.
            if (wt[i - 1] <= j)
            {
                // If the current item can be included, consider two cases:
                // 1. Including the current item and reducing the remaining weight capacity.
                // 2. Not including the current item.
                // Choose the maximum of these two cases.
                dp[i][j] = max({dp[i][j], val[i - 1] + dp[i][j - wt[i - 1]], val[i - 1] + dp[i - 1][j - wt[i - 1]]});
            }

            // If the current item's weight is more than the current capacity, simply copy the value from the row above.
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    // The final value in dp[N][W] represents the maximum value that can be obtained with the given items and capacity.
    return dp[N][W];  // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends