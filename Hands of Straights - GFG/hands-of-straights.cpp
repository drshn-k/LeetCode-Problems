//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
         int size = hand.size();
         if(size % groupSize != 0 or size < groupSize)return false;
         
        //  priority_queue<int, vector<int> , greater<int>> pq;
         map<int , int> mp;
         multiset<int> st(hand.begin() , hand.end());
         
         for(auto i : hand){
             mp[i]++;
         }
        
     
        while(mp.size()>0){
                int k = groupSize;
                bool flag = true;
                auto it = mp.begin();
                int  curr = it->first;
                int count =1;
                mp[curr]--;
                if(mp[curr]==0){
                    mp.erase(curr);
                }
                while(count<k){
                    if(mp[curr+1]>0){
                        curr+=1;
                        count++;
                        mp[curr]--;
                        if(mp[curr]==0){
                            mp.erase(curr);
                        }
                    }else{
                        flag=false;
                        break;
                    }
                    
                }
                if(!flag){
                    return false;
                }
        }
        return true;
    
         
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends