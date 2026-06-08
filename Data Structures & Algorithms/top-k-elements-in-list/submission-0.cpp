class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans(k);
        int size = nums.size();
        unordered_map<int, int> m;
        for(int i=0;i<size;i++){
            m[nums[i]]+=1;
        }
        vector<int> freq_arr;
        vector<int> num_arr;
        for(auto j:m)
        {
            freq_arr.push_back(j.second);
            num_arr.push_back(j.first);
        }
        for(int u=0;u<k;u++){
            int maxl= findMaxLocation(freq_arr);
            ans[u]=num_arr[maxl];
            freq_arr[maxl]=0;
        }


    return ans;
    }
    int findMaxLocation(vector<int>& nums) {
    if (nums.empty()) return -1; 

    int maxIndex = 0;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
    }

    return maxIndex;
}
};
