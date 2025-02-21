class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0;
        int maxChunks = 0;
        for(int i = 0; i < arr.size(); i++) {
            maxChunks = max(maxChunks, arr[i]);
            if(maxChunks == i) {
                chunks++;
            }
        }
        return chunks;
    }
};