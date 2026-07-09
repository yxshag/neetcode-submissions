class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        //calc if the first row and the first col will be 0 or not.
        bool row1=false;
        bool col1=false;
        for(int r=0;r<rows;r++){if(matrix[r][0]==0){col1=true;}}
        for(int c=0;c<cols;c++){if(matrix[0][c]==0){row1=true;}}
        //now we can use the first row and first column to keep track of which rows and columns need to be 0.
        for(int r=1;r<rows;r++){
            for(int c=1;c<cols;c++){
                if(matrix[r][c]==0){
                    matrix[r][0]=0;matrix[0][c]=0;
                }
            }
        }
        //add the zeros in the second iteration
        for(int r=1;r<rows;r++){
            for(int c=1;c<cols;c++){
                if(matrix[r][0]==0||matrix[0][c]==0){
                    matrix[r][c]=0;
                }
            }
        }
        //this is to make the first row and first col 0 if needed
        if(col1){for(int r=0;r<rows;r++){matrix[r][0]=0;}}
        if(row1){for(int c=0;c<cols;c++){matrix[0][c]=0;}}
    }
};
