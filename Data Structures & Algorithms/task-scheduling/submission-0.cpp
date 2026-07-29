class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //mathematical approach , it basically schedules the highest frequency tasks and then fills up the rest of them in the idle gaps
        vector<int> freq_arr(26, 0);
        for(auto i:tasks){
            freq_arr[i-'A']++;
        }
        int fmax=0;
        int countmax=0;
        for(int i=0;i<26;i++){
            if(freq_arr[i]>fmax){
                fmax=freq_arr[i];
                countmax=1;
            }
            else if(fmax==freq_arr[i]){
                countmax++;
            }
        }
        int frame_size = (fmax - 1) * (n + 1) + countmax;
        return max((int)tasks.size(), frame_size);
    }
};
