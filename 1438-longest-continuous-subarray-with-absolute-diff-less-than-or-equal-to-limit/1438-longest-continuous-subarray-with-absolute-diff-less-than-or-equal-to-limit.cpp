class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
		// Time Complexity: O(n lg n)
		// Space Complexity: O(n)
        multiset<int> cnts;
        int j(0), ans(0);
        for (int i = 0; i < nums.size(); ++i) {
            cnts.insert(nums[i]);
            while (*cnts.rbegin() - *cnts.begin() > limit)
                cnts.erase(cnts.find(nums[j++]));
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};