class Solution {
public:
    void heapify(vector<int>& a, int n, int i) {
        while (true) {
            int largest = i;
            int l = 2 * i + 1, r = 2 * i + 2;
            if (l < n && a[l] > a[largest]) largest = l;
            if (r < n && a[r] > a[largest]) largest = r;
            if (largest == i) break;
            swap(a[i], a[largest]);
            i = largest;
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, n, i);

        // repeatedly move max to the end, shrink heap
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
        return nums;
    }
};