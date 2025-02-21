class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        dp[0][0] = 0;
        
        deque<pair<int, int>> dq;
        dq.push_front({ 0, 0 });

        while (!dq.empty()) {
            pair<int, int> front = dq.front();
            int x = front.first, y = front.second;
            dq.pop_front();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newCost = dp[x][y] + (grid[x][y] == i + 1 ? 0 : 1);
                    if (newCost < dp[nx][ny]) {
                        dp[nx][ny] = newCost;
                        if (grid[x][y] == i + 1) {
                            dq.push_front({ nx, ny });
                        }
                        else {
                            dq.push_back({ nx, ny });
                        }
                    }
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};