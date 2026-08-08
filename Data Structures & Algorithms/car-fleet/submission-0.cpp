class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //make position and speed into 1 arr so that we dont lose speed when we sort it
        vector<pair<int, int>> poseed;
        for(int i=0;i<position.size();i++){
            poseed.push_back(make_pair(position[i], speed[i]));
        }
        //sorting descending position
        sort(poseed.begin(), poseed.end(), greater<pair<int, int>>());
        vector<float> time;
        //calculating times
        for(int i=0;i<position.size();i++){
            time.push_back(((float)(target-poseed[i].first)/(float)poseed[i].second));
        }
        //
        int fleets=1;
        float m=(float)time[0];
        for(int i=1;i<position.size();i++){
            fleets+=time[i]>m?1:0;
            m=max(m, time[i]);
        }
        return fleets;
    }
};
