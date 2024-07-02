class Solution {
public:
 void bfs(int row, int col, vector<vector<int>> &visi, vector<vector<char>> &grid) {
            int n = grid.size();
            int m = grid[0].size();
            visi[row][col] = 1;
            queue<pair<int, int>> q;
            q.push({row, col});
            int adrow[] = {-1, 0, 1, 0};
            int adcol[] = {0, 1, 0, -1};
            while (!q.empty()) {
                int currentRow = q.front().first;
                int currentCol = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    
                        int nrow = currentRow + adrow[i];
                        int ncol = currentCol + adcol[i];
                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visi[nrow][ncol] && grid[nrow][ncol] == '1') {
                            visi[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                    
                }
            }
        }

        int numIslands(vector<vector<char>> &grid) {
            int n = grid.size();
            int m = grid[0].size();
            int count = 0;
            vector<vector<int>> visi(n, vector<int>(m, 0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!visi[i][j] && grid[i][j] == '1') {
                        count++;
                        bfs(i, j, visi, grid);
                    }
                }
            }
            return count;
    }
};