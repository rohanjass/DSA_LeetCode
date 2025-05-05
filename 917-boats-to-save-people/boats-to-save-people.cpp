class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(), people.end());
        int st=0;
        int end=n-1;
        int cnt=0;
        while(end>=st){
            if(people[st]+people[end]<=limit){
            
                st++;
                end--;
            }
            else{
                end--;
            }
            cnt++;
        }
        return cnt;
    }
};