class Solution {
public:
    int kthGrammar(int n, int K) {
          // int n;
        for (n = 0, K -= 1; K ; K &= (K - 1)) n++;
        return n & 1;
    }
};