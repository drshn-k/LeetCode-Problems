class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
         double totalTime = 0, currTime = 0, n = customers.size();

        for(int i=0; i<n; i++) {
            int temp = 0;
            if(currTime > customers[i][0]) temp += currTime - customers[i][0];
            else currTime = customers[i][0];
            temp += customers[i][1];
            totalTime += temp;
            currTime += customers[i][1];
        }
        return totalTime / n;
    }
};