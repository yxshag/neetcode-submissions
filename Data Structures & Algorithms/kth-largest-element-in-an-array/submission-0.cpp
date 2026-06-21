class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //make min heap of size k, and keep popping whenever the size becomes mroe than k
        //so that whenever size becomes more than k we remove the minimum element, which means 
        //the min heap keeps track of the k greatest elements in the heap, so the top of the heap would be the k largest element
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(auto i:nums)
        {
            minheap.push(i);
            if(minheap.size()>k){minheap.pop();}
        }
        return minheap.top();

    }
};
