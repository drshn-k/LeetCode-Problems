class Solution {
public:
    int pivotInteger(int n) {
         int prefixSum = (n * (n + 1)) / 2;

        for(int i = 1; i <= n; i++) {
           if(i * i == prefixSum) {
            return i;
           }
        }
        return -1;
    }
};