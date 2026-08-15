class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int freshCount = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {

                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, 1, -1};

        int tm = 0;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            tm = max(tm, t);
            q.pop();

            for (int i = 0; i < 4; i++) {
                int tr = row[i] + r;
                int tc = col[i] + c;

                if (tr < n && tc < m && tr >= 0 && tc >= 0 &&
                    grid[tr][tc] == 1 && !visited[tr][tc]) {

                    q.push({{tr, tc}, t + 1});
                    visited[tr][tc] = true;
                    freshCount--;
                }
            }
        }

        if (freshCount > 0) {
            return -1;
        }

        return tm;
    }
};