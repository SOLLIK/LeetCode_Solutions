class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int colums[9][9] = {0};
        int boxes[9][9] = {0};

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                int num = board[i][j] - '0' - 1;
                int k = i / 3 * 3 + j / 3;

                if(rows[i][num] || colums[j][num] || boxes[k][num]) {
                    return false;
                }

                rows[i][num] = 1;
                colums[j][num] = 1;
                boxes[k][num] = 1;
            }
        }
        return true;
    }
};