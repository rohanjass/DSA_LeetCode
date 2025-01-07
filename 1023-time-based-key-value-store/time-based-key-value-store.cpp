class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>>keyStore;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto& values=keyStore[key];
        int low=0,high=values.size()-1;
        string res="";
        while(low<=high){
            int mid=(low+high)/2;
            if(values[mid].first<=timestamp){
                res=values[mid].second;
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
    return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */