class Solution {
public:
    void def(vector<int>& nums,vector<int>& freq,vector<int>& path,vector<vector<int>>& res){
        if(path.size()==nums.size()){
            res.push_back(path);
        return;
        }

        for(int i=0;i<nums.size();i++){
            if(freq[i]==0){
                path.push_back(nums[i]);
                freq[i]=1;
            
                def(nums,freq,path,res);

                path.pop_back();
                freq[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        vector<int> freq(nums.size(),0);

        def(nums,freq,path,res);

    return res;
    }
};