class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' ||c=='u' || c=='A' ||c=='E' || c=='I' || c=='O' || c=='U') return true;
    return false;
    }
    string reverseVowels(string s) {
        int low=0,high=s.size()-1;
        while(low<high){
            if(!isVowel(s[low])){
                low++;
            } else if(!isVowel(s[high])){
                high--;
            } else{
                char temp=s[low];
                s[low]=s[high];
                s[high]=temp;
                low++;
                high--;
            }
        }
    return s;
    }
};