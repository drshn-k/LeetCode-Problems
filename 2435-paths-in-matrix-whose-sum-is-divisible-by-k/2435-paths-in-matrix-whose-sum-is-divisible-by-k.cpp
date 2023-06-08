class Solution {
public:
   int numberOfPaths(vector<vector<int>>& g, int k) {
    int dp[50001][51] = {}, m = g.size(), n = g[0].size();
    function<int(int, int, int)> dfs = [&](int i, int j, int mod){
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1)
            return (mod + g[i][j]) % k ? 0 : 1;
        if (dp[i * n + j][mod] == 0)
            dp[i * n + j][mod] = (1 + dfs(i + 1, j, (mod + g[i][j]) % k) + 
                dfs(i, j + 1, (mod + g[i][j]) % k)) % 1000000007;
        return dp[i * n + j][mod] - 1;
    };
    return dfs(0, 0, 0);
}
};