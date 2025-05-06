class Solution {
  public:
      vector<int> topKFrequent(vector<int>& nums, int k) {
          std::unordered_map<int, int> num_to_count;
  
          for (int n: nums) {
              ++num_to_count[n];
          }
  
          std::priority_queue<std::pair<int,int>> count_and_num;
  
          for (auto p: num_to_count) {
              count_and_num.push({p.second, p.first});
          }
  
          std::vector<int> top_k;
  
          for (int i = 0; i < k; ++i) {
              top_k.push_back(count_and_num.top().second);
              count_and_num.pop();
          }
  
          return top_k;
      }
  };