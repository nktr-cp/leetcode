class Solution {
  public:
      vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
          vector<vector<int>> result_pairs;
          result_pairs.reserve(k);
  
          using T = tuple<int, int, int>;
          priority_queue<T, vector<T>, greater<T>> min_heap;
          min_heap.emplace(nums1[0] + nums2[0], 0, 0);
  
          set<pair<int, int>> visited;
          while (!min_heap.empty() && result_pairs.size() < k) {
              auto [sum, i, j] = min_heap.top();
              min_heap.pop();
  
              result_pairs.push_back({nums1[i], nums2[j]});
  
              if (i + 1 < nums1.size() && !visited.contains({i + 1, j})) {
                  visited.insert({i + 1, j});
                  min_heap.emplace(nums1[i + 1] + nums2[j], i + 1, j);
              }
              if (j + 1 < nums2.size() && !visited.contains({i, j + 1})) {
                  visited.insert({i, j + 1});
                  min_heap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
              }
          }
  
          return result_pairs;
      }
  };
