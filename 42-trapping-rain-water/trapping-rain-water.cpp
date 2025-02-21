class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) {
            return 0;
        }

        int l = 0;
        int r = height.size() - 1;
        int l_max = height[l];
        int r_max = height[r];
        int res = 0;
        while(l < r) {
            if(l_max < r_max) {
                l++;
                l_max = max(l_max, height[l]);
                res += l_max - height[l];
            }
            else {
                r--;
                r_max = max(r_max, height[r]);
                res += r_max - height[r];
            }
        }
        return res;
    }
};