class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> mp;
        int ans = 1;
        for(auto i:arr)
            ans = max(ans, mp[i]=1+mp[i-difference]);
        return ans;
    }
};