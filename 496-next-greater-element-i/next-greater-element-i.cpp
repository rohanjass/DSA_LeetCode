class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        for(int n:nums2){
            while(!st.empty() && st.top()<n){
                mp[st.top()]=n;
                st.pop();
            }
            st.push(n);
        }

        while(!st.empty()){
            mp[st.top()]=-1;
        st.pop();
        }
        vector<int> res(nums1.size());
        for(int i=0;i<nums1.size();i++){
            res[i]=mp[nums1[i]];
        }
    return res;
    }
};