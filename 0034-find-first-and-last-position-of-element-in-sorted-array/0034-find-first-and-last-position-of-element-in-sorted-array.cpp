class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = nums.size();
        vector<int> res(2, -1);  

        for (int i = 0; i < l; i++) {
            if (target == nums[i]) {
                if (res[0] == -1) {
                    res[0] = i;  
                }
                res[1] = i; 
            }
        }

        return res;
    }
};