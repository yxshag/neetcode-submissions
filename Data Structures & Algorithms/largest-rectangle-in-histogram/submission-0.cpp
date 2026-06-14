class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    stack<pair<int,int>> s;
    int maxArea = 0;

    for(int i = 0; i < heights.size(); i++) {
        int start = i;
        
        while(!s.empty() && s.top().second > heights[i]) {
            auto [idx, h] = s.top(); s.pop();
            maxArea = max(maxArea, h * (i - idx));
            start = idx; 
        }
        s.push({start, heights[i]});
    }
    while(!s.empty()) {
        auto [idx, h] = s.top(); s.pop();
        maxArea = max(maxArea, h * ((int)heights.size() - idx));
    }

    return maxArea;
    }
};
