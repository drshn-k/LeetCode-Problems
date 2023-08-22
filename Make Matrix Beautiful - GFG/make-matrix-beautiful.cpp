//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int sum = INT_MIN;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0, cnt1 = 0;
            for(int j = 0; j < n; j++){
                cnt += matrix[i][j];
                cnt1 += matrix[j][i];
                sum = max(sum, max(cnt, cnt1));
            }
        }
        for(int i = 0; i < n; i++){
            int cnt2 = 0;
            for(int j = 0; j < n; j++){
                cnt2 += matrix[i][j];
            }
            ans += (sum - cnt2);
        }
        return ans;
        // code here 
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends