class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         vector<int> ans;
    int i = 0;
    int n = nums.size();
    while(i < n){
        if(nums[i] != nums[nums[i] - 1]){
            swap(nums[i],nums[nums[i] - 1]);
        }
        else{
            i++;
        }
    }
    for(int i = 0; i < n; i++){
        if(nums[i] != i + 1){
            ans.emplace_back(nums[i]);
        }
    }
    return ans;
    }
};