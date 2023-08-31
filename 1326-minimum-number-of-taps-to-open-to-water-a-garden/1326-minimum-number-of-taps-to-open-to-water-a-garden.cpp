class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int mxx = 0;
        int mnn = 0;
        int open = 0;
        while(mxx<n){
            //check for tap that touhc zero;
            for(int i=0;i<=n;i++){
                int range_left = i-ranges[i];
                int range_right = i+ranges[i];
                if(range_left<=mnn && mxx<range_right){
                    mxx=range_right;
                }
            }
            if(mnn==mxx){
                return -1;
            }
            open++;
            //check for tap range start from min ==max and new max should touch the boundary;
            mnn = mxx;
      }

      return open;
    }
};