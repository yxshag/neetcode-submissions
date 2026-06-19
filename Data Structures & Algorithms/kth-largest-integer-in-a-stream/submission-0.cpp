class KthLargest {
private:
    //creating the variables 
    priority_queue<int, vector<int>, greater<int>> minheap; //syntax for minheap
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        //set the size as k and add all the values specified in the constructor
        size=k;
        for(int i=0;i<nums.size();i++){
            add(nums[i]);
        }
    }
    
    int add(int val) {
        //push the value onto the minheap and then if the number of elements in the heap is more than k, then pop the top element of min heapa
        //this way we can keep a track of the k largest elementhis
        //and the top of the minheap will always be the kth largest element
        minheap.push(val);
        if(minheap.size()>size){minheap.pop();}
        return minheap.top();

    }
};
