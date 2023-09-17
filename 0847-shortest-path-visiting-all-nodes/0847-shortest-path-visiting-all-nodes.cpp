class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int all = (1 << n) - 1;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n+1, vector<int>(all+1,0));
        for(int i=0;i<n;i++){
            int mask =  (1<<i);
            q.push({i, mask});
            vis[i][mask] = 1;
        }
        int steps = 0;
        while(q.size()){
            int k = q.size();
            while(k--){
                auto f = q.front(); q.pop();
                int node = f.first;
                int mask = f.second;
                if(mask==all) return steps;
                for(auto adj:graph[node]){
                    int bothVisited = mask | (1<<adj);
                    if(vis[adj][bothVisited]==0){
                        vis[adj][bothVisited]=1;
                        q.push({adj,bothVisited});
                    }
                }
            }
            steps++;
        }

        return 0;
    }
};