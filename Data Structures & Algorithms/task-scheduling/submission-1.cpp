class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //max heap aproach to solve the question
        //first we make a freq_arr, we have a max heap and a queue
        //heap holds all frequencies, the queue is for cooldown 
        //we pop the top most element in the heap and push it into 
        //the queue with a cooldown time. once the queue and the heap is empty 
        //thats our final answer.
        vector<int> freq_arr(26, 0);
        for(auto i:tasks){
            freq_arr[i-'A']++;
        }
        priority_queue<int> max_heap;
        queue<pair<int, int>> cooldown;
        for(int i=0;i<26;i++){
            if(freq_arr[i]!=0){max_heap.push(freq_arr[i]);}
        }
        int cpu_cyc=0;
        while(!(max_heap.empty()&&cooldown.empty())){
            cpu_cyc++;
            if(!(cooldown.empty())&&cooldown.front().first<cpu_cyc){
                int freq=cooldown.front().second;
                max_heap.push(freq);
                cooldown.pop();
            }
            if(!max_heap.empty()){
                int freq=max_heap.top();
                max_heap.pop();
                freq--;
                if(freq>0){
                    cooldown.push(make_pair(cpu_cyc+n, freq));
                }
            }
        }
        return cpu_cyc;
    }
};
