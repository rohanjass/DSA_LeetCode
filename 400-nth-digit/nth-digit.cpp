class Solution {
public:
    int findNthDigit(int n) {
        long long length=1;
        long long count=9;
        long long start=1;

        while(n>length*count){
            n=n-length*count;
            length++;
            count*=10;
            start*=10;
        }
        start=start+(n-1)/length;
        std::string num=std::to_string(start);
        return num[(n-1)%length]-'0';
    }
};