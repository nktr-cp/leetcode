class Solution {
public:
    bool IsValidLandCell(int row, int column, const vector<vector<char>>& grid, const vector<vector<int>>& visited) {
        int rows = grid.size();
        int columns = grid.front().size();

        return 0 <= row && row < rows &&
               0 <= column && column < columns &&
               grid[row][column] == '1' &&
               !visited[row][column];
    }

    void VisitAllLands(int row, int column, const vector<vector<char>>& grid, vector<vector<int>>& visited) {
        constexpr array<pair<int, int>, 4> directions = {{
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}
        }};

        visited[row][column] = 1;
        for (auto [dr, dc] : directions) {
            int next_row = row + dr;
            int next_column = column + dc;

            if (IsValidLandCell(next_row, next_column, grid, visited)) {
                VisitAllLands(next_row, next_column, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid.front().size();

        int island_count = 0;
        vector<vector<int>> visited(rows, vector<int>(columns));

        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                if (IsValidLandCell(row, column, grid, visited)) {
                    VisitAllLands(row, column, grid, visited);
                    ++island_count;
                }
            }
        }

        return island_count;
    }
};
