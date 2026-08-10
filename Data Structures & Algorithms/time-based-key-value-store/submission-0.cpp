class TimeMap {
private:
    unordered_map<string , vector<pair<int, string>>> m; 
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if(!m.count(key)){
            return "";
        }
        else{
            auto it = upper_bound(m[key].begin(), m[key].end(), timestamp, 
                      [](int target, const pair<int, string>& element) {
                          return target < element.first;
                      });
            if(it==m[key].begin()){
                return "";
            }
            else{
                it--;
                return it->second;//or just do (*it).second
            }
        }
    }
};
