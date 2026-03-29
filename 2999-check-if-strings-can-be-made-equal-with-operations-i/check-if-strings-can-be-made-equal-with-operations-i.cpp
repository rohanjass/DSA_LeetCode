class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2) return true;
        string t1=s1;
        swap(t1[0],t1[2]);
        if(t1==s2) return true;
        t1=s1;
        swap(t1[1],t1[3]);
        if(t1==s2) return true;
        swap(s2[0],s2[2]);
        if(s2==s1) return true;
        swap(s2[1],s2[3]);
        if(s2==s1) return true;
    return false;
    }
};