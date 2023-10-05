class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<int> ans;
    int n = nums.size();
    int prev = INT_MIN;
    int count = 1;
    for(int i =0;i<n;i++){
        if(nums[i] == prev) count++;
        else if(count>n/3 && prev != INT_MIN){
            ans.push_back(prev);
            count = 1;
        }
        else{
            count = 1;
        }
        prev = nums[i];
    }
    if(count > n/3)  ans.push_back(prev);
    return ans;
}
};