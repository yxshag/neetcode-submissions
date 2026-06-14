class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxv=0;
        for(auto i:piles){maxv=max(maxv,i);}
        int ans=maxv;
        int left=1,right=maxv,mid=0;
        while(left<right){
            mid=left+(right-left)/2;
            long long time=0;
            for(int i=0;i<piles.size();i++){time+= (piles[i] + mid - 1) / mid;}
            if(time<=h){ans=mid;right=mid;}
            else{left=mid+1;}

        }       
        return ans;
    }
};
