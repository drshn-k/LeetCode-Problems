class Solution {
public:
    vector<vector<int>> generate(int numRows) {
          vector<vector<int>> result;
        vector<int> current = {1};
        result.push_back(current);

        if(numRows == 1){
            return result;
        }
        
        //numRows - 1 as we already have computed for row = 1 beforehand
        for(int i = 0;i<numRows-1;i++){
            
            //store the previous iteration in a variable
            vector<int> temp = current;
            current = {};
            current.push_back(1);

            for(int j = 0;j<i;j++){
                current.push_back(temp[j] + temp[j+1]);
            }
            current.push_back(1);
            result.push_back(current);
        }

        return result;
    }
};