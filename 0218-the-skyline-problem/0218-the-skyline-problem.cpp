class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector<pair<int, int>> events;

        // Create events
        for (auto& b : buildings) {
            int left = b[0];
            int right = b[1];
            int height = b[2];

            // Start event
            events.push_back({left, -height});

            // End event
            events.push_back({right, height});
        }

        // Sort events
        sort(events.begin(), events.end());

        // Active building heights
        multiset<int> heights;

        // Ground level
        heights.insert(0);

        vector<vector<int>> ans;

        int prevHeight = 0;

        for (auto& event : events) {

            int x = event.first;
            int h = event.second;

            if (h < 0) {
                // Building starts
                heights.insert(-h);
            }
            else {
                // Building ends
                heights.erase(heights.find(h));
            }

            // Current tallest building
            int currHeight = *heights.rbegin();

            // Skyline changed
            if (currHeight != prevHeight) {
                ans.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }

        return ans;
    }
};