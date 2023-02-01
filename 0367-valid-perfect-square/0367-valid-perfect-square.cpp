class Solution {
public:
    bool isPerfectSquare(int num) {
        
        cout << sqrt(num);
        
        bool check = floor(sqrt(num)) == ceil(sqrt(num));
        if(sqrt(num)*sqrt(num) == num and check) return true;
        
        return false;
    }
};