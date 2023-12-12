class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
          std::vector<int> answer;
        
        for (const auto& query : queries) {
            int count = 0;
            int centerX = query[0];
            int centerY = query[1];
            int radius = query[2];
            
            for (const auto& point : points) {
                int x = point[0];
                int y = point[1];
                
                // Calculate the distance between the point and the center of the circle
                double distance = std::sqrt(std::pow(x - centerX, 2) + std::pow(y - centerY, 2));
                
                // Check if the point is inside or on the border of the circle
                if (distance <= radius) {
                    count++;
                }
            }
            
            answer.push_back(count);
        }
        
        return answer;

    }
};