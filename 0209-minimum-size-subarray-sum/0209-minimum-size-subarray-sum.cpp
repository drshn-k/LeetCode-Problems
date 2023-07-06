class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = 0, res = INT_MAX, ws = 0;

        for(; r<n; r++) {
            ws += nums[r];

            if(ws < target)
                continue;

            while(ws >= target) {
                res = min(res, r-l+1);
                ws -= nums[l++];
                
            }
                
        }

        return res == INT_MAX ? 0 : res;
    }
};