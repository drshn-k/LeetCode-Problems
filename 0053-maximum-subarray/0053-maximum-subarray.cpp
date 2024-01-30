class Solution {
public:
    int maxSubArray(vector<int>& v) {
        
        int result = v[0];
        int maxEnd = v[0];
        
        for(int i = 1; i < v.size() ; i++){
            
            maxEnd = max(maxEnd + v[i], v[i]);
            
            result = max(result, maxEnd);
            
        }
        
        return result;
        
    }
};