class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //maxheap to track the closest k points, basically we keep adding all the points to the maxheap
        //everytime the size of the heap becomes more than k, we pop the highest distance(top of the maxheap)
        //this way we are only keeping k smallest distances 
        priority_queue<vector<float>> maxheap;
        for(int i=0;i<points.size();i++)
        {
            float dist=sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            vector<float> arr;
            arr.push_back(dist);
            arr.push_back((float)points[i][0]);
            arr.push_back((float)points[i][1]);
            maxheap.push(arr);
            if(maxheap.size()>k)
            {
                maxheap.pop();
            }
        }
        //now pop the elements one by one and push them into ans array
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            vector<float> a=maxheap.top();
            vector<int> b;
            b.push_back((int)a[1]);
            b.push_back((int)a[2]);
            maxheap.pop();
            ans.push_back(b);
        }
        return ans;
    }
};
