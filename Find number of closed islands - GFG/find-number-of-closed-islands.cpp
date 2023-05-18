//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
    public:
    int bfs(int a,int b, vector<vector<int>> &vis, vector<vector<int>> &grid,int n,int m)
    { 
        vis[a][b]=1;
        queue<pair<int,int>> q;
        q.push({a,b});
        int i,j,f=1;
        int row[4]={0,-1,0,1};
        int col[4]={-1,0,1,0};
        while(q.size()>0)
        {
            pair<int,int> p=q.front();
            q.pop();
            a=p.first;
            b=p.second;
            for(i=0;i<4;i++)
            {
                    int r=a+row[i];
                    int c=b+col[i];
                    if(grid[r][c]==1&&vis[r][c]==0)
                    {
                        if(r==0||r==n-1||c==0||c==m-1)
                        f=0;
                        else
                        {
                            vis[r][c]=1;
                            q.push({r,c});
                        }
                    }
            }
            
        
        
        }
        return f;
    }
    int closedIslands(vector<vector<int>>& grid, int N, int M) {
        int i,j,n=grid.size(),m=grid[0].size(),c=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(i=1;i<n-1;i++)
        {
            for(j=1;j<m-1;j++)
            {
                if(vis[i][j]==0&&grid[i][j]==1)
                {
                    c+=bfs(i,j,vis,grid,n,m);
                }
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends