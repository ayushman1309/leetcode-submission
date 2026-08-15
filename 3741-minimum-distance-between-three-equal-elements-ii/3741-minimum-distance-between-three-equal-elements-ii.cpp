class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> positions;

        for (int i = 0; i < nums.size(); i++) {
            positions[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto& [value, indices] : positions) {

            for (int i = 0; i + 2 < indices.size(); i++) {

                int first = indices[i];
                int last = indices[i + 2];

                int distance = 2 * (last - first);

                ans = min(ans, distance);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};