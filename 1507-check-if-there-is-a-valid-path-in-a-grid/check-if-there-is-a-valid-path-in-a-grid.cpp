class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Directions for each street type
        vector<vector<vector<int>>> dirs = {
            {},
            {{0, -1}, {0, 1}},   // 1
            {{-1, 0}, {1, 0}},   // 2
            {{0, -1}, {1, 0}},   // 3
            {{0, 1}, {1, 0}},    // 4
            {{0, -1}, {-1, 0}},  // 5
            {{0, 1}, {-1, 0}}    // 6
        };

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // If reached destination
            if (x == m - 1 && y == n - 1)
                return true;

            // Explore all valid directions from current cell
            for (auto &d : dirs[grid[x][y]]) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {

                    // Check reverse connection
                    for (auto &back : dirs[grid[nx][ny]]) {
                        if (nx + back[0] == x && ny + back[1] == y) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                            break;
                        }
                    }
                }
            }
        }

        return false;
    }
    
};