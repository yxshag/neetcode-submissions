class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int si=matrix.size();
        int sj=matrix[0].size();
        int li=-1,lj=-1,ri=si,rj=sj;
        int mi;int mj;
        while(li<ri-1){
            mi=(li+ri)/2;
            if(matrix[mi][0]<=target && matrix[mi][sj-1]>=target){break;}
            else if(matrix[mi][0]>target){ri=mi;}
            else{li=mi;}

        }
       while(lj<rj-1){
            mj=(lj+rj)/2;
            if(matrix[mi][mj]==target){return true;}
            else if(matrix[mi][mj]>target){rj=mj;}
            else{lj=mj;}

        }
        return false;
    }
};
