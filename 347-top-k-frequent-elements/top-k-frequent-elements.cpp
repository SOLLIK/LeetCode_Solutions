class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> f;

        for (int n : nums) f[n]++;

        priority_queue<pair<int, int>>pq;

        for (auto& i : f) pq.push({ i.second, i.first });

        vector<int> r;

        for (int i = 0; i < k; ++i) {
            r.push_back(pq.top().second);
            pq.pop();
        }

        return r;
    }
};