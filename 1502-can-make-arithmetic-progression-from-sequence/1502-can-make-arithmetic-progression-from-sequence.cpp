class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        bool flag = false;
        int n = arr.size();
        for(int i = 1; i < n-1 ; i++){
            if(arr[i] - arr[i-1] != arr[i+1] - arr[i]){
                flag = true;
                return false;
            }
        }
        
        return true;
        
        return false;
        return true;
    }
};