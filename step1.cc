class Solution {
    static constexpr int kWaterCell = 0;
    static constexpr int kLandCell = 1;
public:
    bool IsValidLandCell(int row, int column, const vector<vector<int>>& grid, const vector<vector<int>>& visited) {
        int rows = grid.size();
        int columns = grid.front().size();

        return 0 <= row && row < rows &&
               0 <= column && column < columns &&
               grid[row][column] == kLandCell &&
               !visited[row][column];
    }

    int CalculateLandArea(int row, int column, const vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int land_area = 0;

        queue<pair<int, int>> coordinate;
        coordinate.emplace(row, column);
        constexpr array<pair<int, int>, 4> directions = {{
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}
        }};
        while (!coordinate.empty()) {
            auto [row, column] = coordinate.front();
            coordinate.pop();
            if (visited[row][column]) {
                continue;
            }
            visited[row][column] = 1;
            ++land_area;
            for (auto [dr, dc] : directions) {
                int next_row = row + dr;
                int next_column = column + dc;

                if (IsValidLandCell(next_row, next_column, grid, visited)) {
                    coordinate.emplace(next_row, next_column);
                }
            }
        }
        return land_area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid.front().size();

        vector<vector<int>> visited(rows, vector<int>(columns));
        int max_area = 0;
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                if (IsValidLandCell(row, column, grid, visited)) {
                    max_area = max(max_area, CalculateLandArea(row, column, grid, visited));
                }
            }
        }

        return max_area;
    }
};
