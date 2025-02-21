class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        long rev;
        int xcopy = x;
        while(x > 0) {
            rev = rev * 10 + x % 10;
            x/=10;
        }

        return rev == xcopy; 
    }
};