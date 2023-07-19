class Solution {
public:
   static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end(), cmp);
      // we have alreay sorted, we can compare with right point
      
      for(int i=0;i<intervals.size();i++)
      {
        cout << intervals[i][0] << "," << intervals[i][1] << endl;
      }
      int prev = intervals[0][1];
      int count = 0;
      for(int i=1;i<intervals.size();i++)
      {
        if(prev > intervals[i][0])
        {
          count++;
        }
        else
        {
          prev = intervals[i][1];
        }
      }

      return count;
    }
};