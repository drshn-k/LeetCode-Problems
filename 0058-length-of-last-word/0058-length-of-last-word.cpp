class Solution {
public:
    int lengthOfLastWord(string s) {

        stringstream ss(s);
        string ans = "";
        string word;
        while(ss >> word){
            ans = word;
        }
//   cout << ans;
        return ans.size();
      
        
    }
};