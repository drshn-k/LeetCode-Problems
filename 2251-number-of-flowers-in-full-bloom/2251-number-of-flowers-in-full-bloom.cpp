class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> s, e; // Create vectors 's' and 'e' to store the start and end days of flowers' bloom periods.

        // Step 1: Extract start and end days of flowers' bloom periods and store them in 's' and 'e' respectively.
        for (auto a : flowers) {
            s.push_back(a[0]);
            e.push_back(a[1]);
        }

        // Step 2: Sort the 's' and 'e' vectors.
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        vector<int> ans; // Create a vector to store the answers.

        // Step 3: Iterate through the 'people' array.
        for (auto a : people) {
            // Find the position of 'a' in the 's' and 'e' vectors using binary search.
            auto i = upper_bound(s.begin(), s.end(), a);
            auto j = lower_bound(e.begin(), e.end(), a);

            int c = i - s.begin(); // Calculate the number of flowers that bloomed before 'a'.
            int d = j - e.begin(); // Calculate the number of flowers that finished blooming before or on 'a'.

            ans.push_back(c - d); // Calculate the answer for this person and add it to the 'ans' vector.
        }
        return ans; // Return the vector of answers.
    }
};