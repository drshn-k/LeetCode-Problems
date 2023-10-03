class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums) mp[i]++;
        vector<int> v;
        for(auto i = 0 ; i<nums.size() ; i++){
            if(mp[nums[i]]!=0){
                v.push_back(mp[nums[i]]);
                mp[nums[i]] = 0;
            }
        } 
        int ans = 0;
        for(auto i = 0 ; i<v.size() ; i++){
            int temp = v[i]*(v[i]-1)/2;
            ans+=temp;
        }
        return ans;  
    }
};