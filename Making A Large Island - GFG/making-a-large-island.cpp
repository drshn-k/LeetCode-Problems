//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {-1, 0, 1, 0};
    
    
    void dfs(int i, int j, vector<vector<int>>&visited, vector<vector<int>>&grid, int &currentgp, int &n ){
        visited[i][j] = currentgp;
        
        //go to its neighbour
        for(int k = 0; k<4; k++){
            int r = i + dr[k];
            int c = j + dc[k];
            if(r >= 0 && r < n && c>=0 && c< n && grid[r][c] == 1 && !visited[r][c]){
                dfs(r, c, visited, grid, currentgp, n);
            }
        }
        return;
    }
    
    
    int solve(vector<vector<int>>&grid, int &n){
        vector<vector<int>>visited(n, vector<int>(n, 0));
        int currentgrp = 1;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    dfs(i, j, visited, grid, currentgrp, n);
                    currentgrp++;
                }
            }
        }
        
        
        unordered_map<int, int> mp;
        int ans = 0;
        //to store the size of each connected component
        for(int i = 0; i<n; i++){
            for(int j= 0; j<n; j++){
                if(visited[i][j] != 0){
                    mp[visited[i][j]]++;
                }
            }
        }
        
        //update the answer
        for(auto it: mp){
            ans = max(ans, it.second);
        }
        
        
        //traverse and try to make 0 to 1
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0){
                    set<int>groups_taken;
                    
                    for(int k = 0; k<4; k++){
                        int r = i + dr[k];
                        int c = j + dc[k];
                        if(r >= 0 && r < n && c >= 0 && c< n && grid[r][c] != 0){
                            int group_num = visited[r][c];
                            groups_taken.insert(group_num);
                        }
                    }
                    int tempans = 0;
                    for(auto it: groups_taken){
                        tempans += mp[it];
                    }
                    ans = max(ans, tempans+1);
                    
                }
            }
        }
        
        return ans;
    }

    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        int n = grid.size();
        int ans = solve(grid, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends