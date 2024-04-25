class Solution {
public:
    int longestIdealString(string s, int k) {
                
   int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(27, 0));
    int maxi = 1;
    for (int i = (n - 1); i >= 0; i--)
    {
        for (int j = 0; j <= 26; j++)
        {
            int take = 0, notTake = 0;
            if (abs(j - (s[i] - 'a')) <= k || j == 26)
            {
                take = 1 + dp[i + 1][s[i]-'a'];
            }
            notTake = dp[i + 1][j];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[0][26];
    }
};