class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        int row[] = {-1, 0, +1, 0};
        int col[] = {0, +1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;

            int s = q.front().second;

            q.pop();
            dist[r][c] = s;
            for (int i{0}; i < 4; i++) {
                int tr = row[i] + r;
                int tc = col[i] + c;

                if (tr >= 0 && tr < n && tc >= 0 && tc < m &&
                    visited[tr][tc] == false) {
                    visited[tr][tc] = true;
                    q.push({{tr, tc}, s + 1});
                }
            }
        }
        return dist;
    }
};