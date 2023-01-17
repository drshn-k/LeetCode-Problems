class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        int n = nums.size();
        int tworaisedton = (1<<n);
        
        for( int i = 0 ; i < tworaisedton ; i++){
            vector<int> subset;
            for(int j = 0 ; j < n ; j++){
                if((i & (1<<j)) != 0){
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }
        
        return ans;
    }
};