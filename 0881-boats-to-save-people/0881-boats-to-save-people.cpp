class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       
        // sort vector
        sort(people.begin(),people.end());
        
        int i = 0, j = people.size() - 1,cnt = 0;
        
        while(i <= j)
        {   
           
            if(people[i] + people[j] <= limit)
            {
                ++i;
                --j;
            }
       
            else
                --j;
            
            ++cnt;  
        }
        
        return cnt;
        
    }
	// for github repository link go to my profile.
};