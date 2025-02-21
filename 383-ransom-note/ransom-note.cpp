class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazineMap;

        for (int i = 0; i < magazine.size(); i++) {
            char m = magazine[i];

            int count = magazineMap.count(m) ? magazineMap[m] : 0;
            magazineMap[m] = count + 1;
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            char r = ransomNote[i];

            int count = magazineMap.count(r) ? magazineMap[r] : 0;

            if (count == 0) {
                return false;
            }

            magazineMap[r] = count - 1;
        }
        return true;
    }
};