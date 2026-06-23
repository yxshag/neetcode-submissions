class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {        
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        set<pair<int,int>> s;
        //push all rotten fruits into queue as sources of rotting
        //push all the fresh fruits into an unordered set to keep track how many fresh friuts are remaining
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(grid[i][j]==1){
                    s.insert({i,j});
                }
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};//neighbors
        int count=0;//to count how many time we are doing bfs
        q.push({-6,-6});//-6 is just a placeholder, it can be any negative number which is never possible
        //expanding outward from ALL sources at once
        while (q.size()>1) {
            if(q.front().first==-6){count++;q.pop();q.push({-6, -6});continue;}//if its a null value then increment count, insert the null at the end and pop the current null
            auto [r, c] = q.front();
            q.pop();
            cout<<count<<endl;
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                // skip out of bounds
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if (grid[nr][nc] == 0) continue;   //skip empty cells also 
                if (grid[nr][nc] == 2) continue;  // already rotten, so if we dont put this condition, it will keep rotting each other and the time will be infinite

                grid[nr][nc] = 2;// if it is next to a rotten fruit, then make it rotten 
                s.erase({nr,nc});//once its rotten, remove it from the fresh fruit set
                q.push({nr, nc});//push this as a new source(kind of)
                cout<<nr<<nc<<endl;
            }
        }
        if(!s.empty()){return -1;}
        return count;
    }
};
