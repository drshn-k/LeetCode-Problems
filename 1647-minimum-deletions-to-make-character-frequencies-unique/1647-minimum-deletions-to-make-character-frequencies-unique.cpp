class Solution {
public:
    int minDeletions(string s) {
        vector<pair<int,int>> v;

        unordered_map<int,int> mp;
        int size = 0;
        for(char c:s){
            mp[c-'a']++;
            size = max(mp[c-'a'],size);
        }

        vector<int> freq(size+1,0);

        for(int i=0;i<26;i++){
            if(mp.find(i)!=mp.end()){

                v.push_back({mp[i],i});
                freq[mp[i]]++;
            }
        }

        int ind = size;
        int count = 0;
        for(int i=size;i>=0;i--){

            while(freq[i]>1){

                while(!(freq[ind]==0 && ind<=i)){
                    ind--;
                }

                count += (i-ind);

                if(ind!=0){
                    freq[ind]++;
                }
                freq[i]--;
            }
        }



        
        
        return count;


        
        
        return count;


    }
};