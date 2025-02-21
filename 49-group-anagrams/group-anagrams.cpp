class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto& s : strs ) {
            auto k = s;
            sort(k.begin(), k.end());
            m[k].push_back(move(s));
        }
         vector<vector<string>> result;
        result.reserve(m.size());
        for (auto [l , p] : m) result.push_back(move(p));
        return result;
    }
};