class Solution 
{
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> sum(n, 0), count(n, 0);

        dfs_1(adj, 0, -1, sum, count);
        dfs_2(adj, 0, -1, sum, count);
        return sum;
    }
    void dfs_2(vector<vector<int>>& adj, int root, int par, vector<int>& sum, vector<int>& count)
    {
        for(int i=0;i<adj[root].size();i++)
        {
            if(adj[root][i] == par) continue;

            sum[adj[root][i]] += (sum[root] - sum[adj[root][i]] - count[adj[root][i]]) + (adj.size() - count[adj[root][i]]);  

            dfs_2(adj, adj[root][i], root, sum, count);
        }
    }
    void dfs_1(vector<vector<int>>& adj, int root, int par, vector<int>& sum, vector<int>& count)
    {

        for(int i=0;i<adj[root].size();i++)
        {
            if(adj[root][i] == par) continue;

            dfs_1(adj, adj[root][i], root, sum, count);
            sum[root] += sum[adj[root][i]] + count[adj[root][i]];
            count[root] += count[adj[root][i]];
        }
        count[root]++;
    }
};