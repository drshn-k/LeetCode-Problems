class Solution {
public:
    string removeKdigits(string num, int k) {
         string res;
        int digitsToKeep = num.size()-k;

        for (char digit : num) {
            while (k > 0 && !res.empty() && res.back() > digit) {
                res.pop_back(); //found peak value, removing it
                k--;
            }
            res.push_back(digit);
        }

        //cutting off remaining digits from the end
        res.resize(digitsToKeep);

        //removing prefix zeros
        int start = 0;
        while (start < res.size() && res[start] == '0') {
            ++start;
        }
        res = res.substr(start);

        return res == "" ? "0" : res; 
    }
};