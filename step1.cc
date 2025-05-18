class Solution {
    void VisitAllLand(int i, int j, vector<vector<int>>& visited, const vector<vector<char>>& grid) {
        const size_t m = grid.size();
        const size_t n = grid.front().size();
        const int dx[4] = {1, -1, 0, 0};
        const int dy[4] = {0, 0, 1, -1};

        visited[i][j] = 1;
        for (int k = 0; k < 4; ++k) {
            int next_i = i + dx[k];
            int next_j = j + dy[k];

            if (next_i < m && next_j < n && !visited[next_i][next_j] && grid[next_i][next_j] == '1') {
                VisitAllLand(next_i, next_j, visited, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        const size_t m = grid.size();
        const size_t n = grid.front().size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int number_of_islands = 0;
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || visited[i][j]) {
                    continue;
                }
                VisitAllLand(i, j, visited, grid);
                ++number_of_islands;
            }
        }

        return number_of_islands;
    }
};
