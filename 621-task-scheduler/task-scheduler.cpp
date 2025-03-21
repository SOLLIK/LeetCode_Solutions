class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(int task : tasks) {
            count[task - 'A']++;
        }

        sort(count.begin(), count.end());
        int maxf = count[25];
        int idel = (maxf - 1) * n;
        for(int i = 24; i >= 0; i--) {
            idel -= min(maxf - 1, count[i]);
        }
        return max(0, idel) + tasks.size();
    }
};