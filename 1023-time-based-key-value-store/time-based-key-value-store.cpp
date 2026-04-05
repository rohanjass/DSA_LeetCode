class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> keyStore;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto& arr=keyStore[key];
        int l=0,h=arr.size()-1;
        string res="";
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid].first<=timestamp){
                res=arr[mid].second;
                l=mid+1;
            } else {
                h=mid-1;
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