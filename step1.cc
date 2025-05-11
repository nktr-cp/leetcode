class Solution {
  public:
      vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
          priority_queue<tuple<int,int,int>> max_heap;
  
          for (size_t i = 0; i < nums1.size(); ++i) {
              for (size_t j = 0; j < nums2.size(); ++j) {
                  if (max_heap.size() < k) {
                      max_heap.push({nums1[i] + nums2[j], nums1[i], nums2[j]});
                      continue;
                  }
  
                  if (get<0>(max_heap.top()) <= nums1[i] + nums2[j]) {
                      break;
                  }
                  max_heap.pop();
                  max_heap.push({nums1[i] + nums2[j], nums1[i], nums2[j]});
              }
          }
  
          vector<vector<int>> result_pairs;
  
          while (!max_heap.empty()) {
              auto tp = max_heap.top();
              max_heap.pop();
              result_pairs.push_back({get<1>(tp), get<2>(tp)});
          }
  
          reverse(result_pairs.begin(), result_pairs.end());
  
          return result_pairs;
      }
  };
