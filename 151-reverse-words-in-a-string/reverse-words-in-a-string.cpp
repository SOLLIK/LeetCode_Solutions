class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int r = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] != ' ') {
                if(r != 0) {
                    s[r++] = ' ';
                }
                int start = r;
                while(i < n && s[i] != ' ') {
                    s[r++] = s[i++];
                }
                reverse(s.begin() + start, s.begin() + r);
            }
        }
        s.resize(r);
        return s;
    }
};