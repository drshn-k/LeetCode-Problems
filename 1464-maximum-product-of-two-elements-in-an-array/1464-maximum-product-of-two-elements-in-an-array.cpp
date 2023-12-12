class Solution {
public:
    int maxProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
    int n = nums.size();
    return (nums[n-1] - 1) * (nums[n-2] - 1);

    }
};