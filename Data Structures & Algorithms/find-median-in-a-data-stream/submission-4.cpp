class MedianFinder {
private:
    //declaring 2 pqs, one is hi and one is lo, to keep track of upper half of numbers and lower half of numbers 
    priority_queue<int> lo;                              // max-heap has smaller half
    priority_queue<int, vector<int>, greater<int>> hi;    // min-heap has larger half
public:
    MedianFinder() {}

    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        //the idea is to maintain both the sizes of the list to be almost equal
        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        //odd number of elements
        if (lo.size() > hi.size()) return lo.top();
        //even number of elements
        return ((double)lo.top() + (double)hi.top()) / 2.0;
    }
};
