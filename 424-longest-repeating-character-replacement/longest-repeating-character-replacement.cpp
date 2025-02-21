class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26);
        int r = 0;
        int res = 0;
        int n = s.size();
        int l = 0, maxf = 0;
        while(r < n) {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);
            if(r - l + 1 - maxf > k) {
                hash[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};