class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> farmlands;
        int rows = land.size(); 
        int cols = land[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (land[i][j] == 0 || (j > 0 && land[i][j - 1] == 1) || (i > 0 && land[i - 1][j] == 1)) {
                    continue;
                }

                int topLeftX = i;
                int topLeftY = j;
                int bottomRightX = i;
                int bottomRightY = j;
              
                while (bottomRightX + 1 < rows && land[bottomRightX + 1][j] == 1) {
                    bottomRightX++;
                }
              
                while (bottomRightY + 1 < cols && land[bottomRightX][bottomRightY + 1] == 1) {
                    bottomRightY++;
                }
              
                farmlands.push_back({topLeftX, topLeftY, bottomRightX, bottomRightY});
            }
        }

        return farmlands;
    }
};