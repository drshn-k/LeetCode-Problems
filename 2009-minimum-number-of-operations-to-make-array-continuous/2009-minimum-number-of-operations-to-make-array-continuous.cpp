class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        sort(nums.begin(),nums.end());
        int actual=nums.size();
        nums.erase(unique(begin(nums),end(nums)),end(nums)); 
        int mini=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            int target=nums[i]+actual-1;
            auto it=upper_bound(nums.begin()+i,nums.end(),target);
            int count=distance(nums.begin()+i,it);
            if(nums.size()-count<mini)
                mini=nums.size()-count;
          }
            return actual-nums.size()+mini;
    }
};