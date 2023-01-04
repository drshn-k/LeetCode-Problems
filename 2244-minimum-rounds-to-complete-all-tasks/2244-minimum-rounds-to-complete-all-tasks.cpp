class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int , int> mp;
        
        for(auto i :tasks){
            mp[i]++;
        }
        int ans = 0 ;
        
        for(auto i: mp){
           
            int an = i.second/3;
            int rem = i.second%3;
            
            if(i.second == 1) return -1;
            
            else if(rem == 0) ans = ans + an;
            
            else ans = ans + an + 1;
            
            
            
            
        }
        
        return ans;
    }
};