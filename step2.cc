#include <numeric>

class Dsu {
    vector<int> parent_;
    public:
        Dsu(int n) : parent_(n) {
            iota(parent_.begin(), parent_.end(), 0);
        }

        int find(int x) {
            if (parent_[x] != x) {
                // 経路圧縮
                parent_[x] = find(parent_[x]);
            }
            return parent_[x];
        }

        bool merge(int x, int y) {
            int rx = find(x), ry = find(y);
            if (rx == ry) {
                return false;
            }
            parent_[ry] = rx;
            return true;
        }
};

class Solution {
public:
    /**
     * @param n: the number of vertices
     * @param edges: the edges of undirected graph
     * @return: the number of connected components
     */
    int countComponents(int n, vector<vector<int>> &edges) {
        Dsu union_find(n);
        int num_components = n;

        for (const auto& edge : edges) {
            if (union_find.merge(edge[0], edge[1])) {
                --num_components;
            }
        }

        return num_components;
    }
};
