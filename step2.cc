class Solution {
    static constexpr int kWaterCell = 0;
    static constexpr int kLandCell = 1;
public:
    bool IsValidLandCell(int row, int column, const vector<vector<int>>& grid, const vector<vector<int>>& marked) {
        int rows = grid.size();
        int columns = grid.front().size();

        return 0 <= row && row < rows &&
               0 <= column && column < columns &&
               grid[row][column] == kLandCell &&
               !marked[row][column];
    }

    int CalculateLandArea(int row, int column, const vector<vector<int>>& grid, vector<vector<int>>& marked) {
        int land_area = 0;

        queue<pair<int, int>> coordinate;
        coordinate.emplace(row, column);
        marked[row][column] = 1;
        while (!coordinate.empty()) {
            auto [row, column] = coordinate.front();
            coordinate.pop();
            ++land_area;

            auto try_enqueue = [&](int next_row, int next_column){
                if (IsValidLandCell(next_row, next_column, grid, marked)) {
                    marked[next_row][next_column] = 1;
                    coordinate.emplace(next_row, next_column);
                }
            };

            try_enqueue(row + 1, column);
            try_enqueue(row, column + 1);
            try_enqueue(row - 1, column);
            try_enqueue(row, column - 1);
        }
        return land_area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid.front().size();

        vector<vector<int>> marked(rows, vector<int>(columns));
        int max_area = 0;
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                if (IsValidLandCell(row, column, grid, marked)) {
                    max_area = max(max_area, CalculateLandArea(row, column, grid, marked));
                }
            }
        }

        return max_area;
    }
};
