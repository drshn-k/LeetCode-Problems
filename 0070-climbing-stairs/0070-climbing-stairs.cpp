class Solution {
public:
    int climbStairs(int n) {
         vector<long long> v;

        long long first = 1;
        long long second = 1;
        v.push_back(first);
        v.push_back(second);
      for( int i = 2; i <= n ; i++){
          int ans = first + second;
          first = second;
          second = ans;
            v.push_back(ans);

      }
    return v[n];
    }
};