class Solution {
  public:
      vector<int> topKFrequent(vector<int>& nums, int k) {
          unordered_map<int, int> number_to_count;
          for (int n: nums) {
              ++number_to_count[n];
          }
  
          priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> count_and_number;
          for (auto [number, count]: number_to_count) {
              count_and_number.push({count, number});
  
              if (count_and_number.size() > k) {
                  count_and_number.pop();
              }
          }
  
          vector<int> top_k;
          for (int i = 0; i < k; ++i) {
              [[maybe_unused]] auto [_, number] = count_and_number.top();
              top_k.push_back(number);
              count_and_number.pop();
          }
  
          return top_k;
      }
  };