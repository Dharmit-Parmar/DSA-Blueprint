class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        // {{row, col}, steps}
        queue<pair<pair<int, int>, int>> q;

        q.push({{entrance[0], entrance[1]}, 0});
        maze[entrance[0]][entrance[1]] = '+';

        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int tr = row[i] + r;
                int tc = col[i] + c;

                if (tr >= 0 && tr < n && tc >= 0 && tc < m) {

                    if (maze[tr][tc] == '.') {

                        if (tr == 0 || tr == n - 1 || tc == 0 || tc == m - 1) {
                            return steps + 1;
                        }

                        q.push({{tr, tc}, steps + 1});
                        maze[tr][tc] = '+';
                    }
                }
            }
        }

        return -1;
    }
};