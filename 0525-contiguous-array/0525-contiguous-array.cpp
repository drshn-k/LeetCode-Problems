class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int , int> mapping;
        int sum = 0;
        int ans = 0;
        int temp = 0;
        mapping[0] = -1;
        for(int i = 0 ; i<n ; i++){
            if(nums[i] == 1)
                sum += 1;
            else if(nums[i] == 0)
                sum += -1;
            
            if(mapping.find(sum)==mapping.end()){
                mapping[sum] = i;
            }
            else if(mapping.find(sum)!= mapping.end()){
                temp = i - mapping[sum];
                ans = max(temp , ans);
            }
            
        }
        return ans;   
    }
};