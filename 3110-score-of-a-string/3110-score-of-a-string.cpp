class Solution {
public:
    int scoreOfString(string s) {
                int n = s.length();
       int count =0;
        for(int i=1;i<n;i++){
            char ch1 = s[i-1];
            char ch2 = s[i];
            count+= abs(int(ch1)-int(ch2));
        }
        return count;

    }
};