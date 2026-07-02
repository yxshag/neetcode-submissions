class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int curr = nums[i];
            // If the current number is negative, it swaps the maximum and minimum possibilities
            if (curr < 0) {
                swap(max_so_far, min_so_far);
            }

            // The choice is either to start a new subarray at curr, 
            // or continue the existing subarray product
            max_so_far = max(curr, max_so_far * curr);
            min_so_far = min(curr, min_so_far * curr);
            result = max(result, max_so_far);
        }

        return result;
    }
};