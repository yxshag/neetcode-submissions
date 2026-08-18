class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals by their start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // Step 2: Traverse and merge overlapping intervals
        for (const auto& interval : intervals) {
            // If ans is empty or there's no overlap
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            } 
            // Overlap exists: update the end time to the maximum reachable end
            else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};
