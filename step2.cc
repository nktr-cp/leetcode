class Solution {
public:
    bool IsValidLandCell(int row, int column, const vector<vector<char>>& grid, vector<vector<int>>& visited) {
        int rows = grid.size();
        int columns = grid.front().size();

        return 0 <= row && row < rows &&
               0 <= column && column < columns &&
               !visited[row][column] &&
               grid[row][column] == '1';
    }

    void VisitAllLand(int row, int column, const vector<vector<char>>& grid, vector<vector<int>>& visited) {
        int rows = grid.size();
        int columns = grid.front().size();

        constexpr array<pair<int, int>, 4> directions = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
        visited[row][column] = 1;
        for (auto [dr, dc] : directions) {
            int next_row = row + dr;
            int next_column = column + dc;

            if (IsValidLandCell(next_row, next_column, grid, visited)) {
                VisitAllLand(next_row, next_column, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid.front().size();

        vector<vector<int>> visited(rows, vector<int>(columns));
        int island_count = 0;

        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                if (IsValidLandCell(row, column, grid, visited)) {
                    VisitAllLand(row, column, grid, visited);
                    ++island_count;
                }
            }
        }

        return island_count;
    }
};

