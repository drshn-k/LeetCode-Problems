class Solution {
public:
    int recursive(int i, int j, int m, int n)
{
    if (i == 0 and j == 0)
    {
        return 1;
    }

    int up = 0;
    int left = 0;

    if (i - 1 >= 0)
    {
        up = recursive(i - 1, j, m, n);
    }

    if (j - 1 >= 0)
    {
        left = recursive(i, j - 1, m, n);
    }

    return up + left;
}

int DP(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 and j == 0)
    {
        return dp[0][0]=1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = 0;
    int left = 0;
    if (i - 1 >= 0)
    {
        up = DP(i - 1, j, dp);
    }

    if (j - 1 >= 0)
    {
        left = DP(i, j - 1, dp);
    }

    return dp[i][j] = up + left;
}

int tabulation(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
            {
                continue;
            }
            else
            {
                int up = 0;
                int left = 0;
                if (i - 1 >= 0)
                {
                    up = dp[i - 1][j];
                }
                if (j - 1 >= 0)
                {
                    left = dp[i][j - 1];
                }
                dp[i][j] = left + up;
            }
        }
    }
    return dp[m - 1][n - 1];
}

int uniquePaths(int m, int n) 
{
    // vector<vector<int>>visited(n,vector<int>(m,0));
    // int count=0;
    // solve(0,0,n,m,visited,count);

    // vector<vector<int>> dp(m,vector<int>(n,-1));
    // dp[0][0]=1;
    // return DP(m-1,n-1,dp);

    return tabulation(m,n);

}
};