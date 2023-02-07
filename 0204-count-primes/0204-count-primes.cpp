class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0;
        vector<bool> prime(n , true);

        prime[0] = prime[1] = false;

         for(int i = 2 ; i < n ; i++){
        
        if(prime[i]){
            for(int j = 2*i ; j < n ; j = j + i){
                prime[j] = false;
            }
        }
        
    }

        int cnt = 0;

        for(auto i : prime){
            if(i)cnt++;
        }
        //    for(auto i : prime) cout << i << " ";
    

        return cnt;
    }
};