class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            int currentValue = romanValue(s[i]);
            int nextValue = ( i + 1 < s.size()) ? romanValue(s[i + 1]) : 0;
            if(currentValue < nextValue) {
                ans -= currentValue;
            }
            else{
                ans += currentValue;
            }
        }
        return ans;
    }
private:
    int romanValue(char c) {
        if(c == 'I') return 1;
        if(c == 'V') return 5;
        if(c == 'X') return 10;
        if(c == 'L') return 50;
        if(c == 'C') return 100;
        if(c == 'D') return 500;
        if(c == 'M') return 1000;

        return 0;
    }
};