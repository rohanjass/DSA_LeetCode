class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' ||c=='u' || c=='A' ||c=='E' || c=='I' || c=='O' || c=='U') return true;
    return false;
    }
    string sortVowels(string s) {
        vector<char>vowels;
        for(char c:s){
            if(isVowel(c)){
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(),vowels.end());
        int ind=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i]=vowels[ind];
                ind++;
            }
        }
    return s;    
    }
};