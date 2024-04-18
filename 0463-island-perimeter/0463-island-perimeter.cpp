class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
    int len = 0;
        for( int r = 0; r < grid.size(); r++){
            for( int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    if(r == 0)
                        len++;
                    else if(grid[r-1][c] == 0)
                        len++;
                    if(c == 0)
                        len++;
                    else if(grid[r][c-1] == 0)
                        len++;
                    if(r == grid.size()-1)
                        len++;
                    if(c == grid[0].size()-1)
                        len++;
                }
                else{
                    if(r>0 && grid[r-1][c] == 1)
                        len++;
                    if(c>0 && grid[r][c-1] == 1)
                        len++;
                }
            }
        }
        return len;     
    }
};