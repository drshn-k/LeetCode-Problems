class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n=p.size();
        vector<pair<int,int>>adj[n+1];
//make complete graph of n node
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d = abs(p[i][0] - p[j][0]) + abs(p[i][1]-p[j][1]);
                adj[i].push_back({d,j});
                adj[j].push_back({d,i});
            }
        }
//apply prims algorith
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        int ans = 0;
        vector<int>vis(n+1,0);
//pop minimum edge and add it in ans
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            if(vis[it.second]==1)continue;
            vis[it.second] = 1;
            ans += it.first;
            for(auto i:adj[it.second]){
                q.push(i);
            }
        }
        return ans;
    }
};