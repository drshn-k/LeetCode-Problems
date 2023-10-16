class Solution {
public:
   vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);

        for (int n = 2; n <= rowIndex; n++) {
            int prev = 1;
            for (int r = 1; r < n; r++) {
                int temp = ans[r];
                ans[r] += prev;
                prev = temp;
            }
        }

        return ans;
    }
};