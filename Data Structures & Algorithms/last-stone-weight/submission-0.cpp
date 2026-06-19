class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //make a max heap and process data
        priority_queue<int> maxheap;
        for(auto stone:stones){
            maxheap.push(stone);
        }
        //keep running loop till we have no more than 1 element in the heap
        while(maxheap.size()>1){
            int max1=maxheap.top();maxheap.pop();
            int max2=maxheap.top();maxheap.pop();
            if(max1>max2){maxheap.push(max1-max2);}
        }
        //return statement
        if(maxheap.size()==1){return maxheap.top();}
        return 0;
    }
};
