class Solution {
public:
    //making all vars global so we can define another function in which we do depth first search
    vector<vector<int>> res;
    set<vector<int>> s;
    vector<int> comb;
    vector<int> cand;
    int tar;
    //dfs recursive function that takes index i and sum until i
    void dfs(int start,int sum){
        if (sum == tar) {//base case
            res.push_back(comb);
            return;
        }
        for (int i = start; i < cand.size(); i++) {
            if (sum + cand[i] > tar) break;          // sorted, so no point going further
            if (i > start && cand[i] == cand[i-1]) continue; // skip duplicates at this level

            comb.push_back(cand[i]);
            dfs(i + 1, sum + cand[i]);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //it is better to sort it and do so that we can directly ignore the cases which are same value
        sort(candidates.begin(),candidates.end());
        cand=candidates;
        tar=target;
        //run the dfs
        dfs(0,0);
        //only copy non-duplicate elements
        for(auto i:s){res.push_back(i);}
        return res;
    }
};
