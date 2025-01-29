class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string word="";
        int segment=0;
        while(ss >> word){
            segment++;
        }
    return segment;
    }
};