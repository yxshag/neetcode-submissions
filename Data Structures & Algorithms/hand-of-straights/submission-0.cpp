class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //sort the hand, make the hashmap
        sort(hand.begin(),hand.end());
        if(hand.size()%groupSize!=0){
            return false;
        }
        int count=hand.size();
        unordered_map<int,int> m;
        for(int i=0;i<count;i++){
            m[hand[i]]++;
        }
        //go through the original hand, and everytime we get the smallest number, we reduce the frequency of its successors by 1 and do it for the whole list
        for(int i=0;i<count;i++){
            if(m[hand[i]]!=0)
            {
                for(int j=0;j<groupSize;j++){
                    if(m[hand[i]+j]>=1){
                        m[hand[i]+j]--;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
