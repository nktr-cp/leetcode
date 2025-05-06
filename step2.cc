struct Frequency {
  int number;
  int count;

  Frequency(int c, int n): count(c), number(n) {}

  bool operator>(const Frequency& other) const {
      return this->count > other.count;
  }
};

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
      std::unordered_map<int, int> number_to_count;
      for (int n: nums) {
          ++number_to_count[n];
      }

      std::priority_queue<Frequency, std::vector<Frequency>, std::greater<Frequency>> min_heap;
      for (auto [number, count]: number_to_count) {
          min_heap.push(Frequency(count, number));

          if (min_heap.size() > k) {
              min_heap.pop();
          }
      }

      std::vector<int> top_k;
      for (int i = 0; i < k; ++i) {
          top_k.push_back(min_heap.top().number);
          min_heap.pop();
      }

      assert(min_heap.size() == 0);
      return top_k;
  }
};