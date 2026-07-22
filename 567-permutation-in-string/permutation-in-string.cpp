class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<int> count1(26,0);
        vector<int> count2(26,0);

        if(n1>n2) return false;

        for(int i=0;i<n1;i++){
            count1[s1[i]-'a']++;
        }

        for(int i=0;i<n2;i++){
            count2[s2[i]-'a']++;

            if(i>=n1) count2[s2[i-n1]-'a']--;

            if(count1==count2) return true;
        }
    return false;
    }
};