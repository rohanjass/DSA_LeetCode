class Solution {
public:
    bool dfs(int num,unordered_set<int>& set){
        if(num==1) return true;
        if(set.count(num)) return false;
        set.insert(num);
        int sum=0;
        while(num!=0){
            int number=num%10;
            sum+=(number)*(number);
            num=num/10;
        }
    return dfs(sum,set);
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        return dfs(n,set);
    }
};