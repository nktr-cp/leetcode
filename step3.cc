class KthLargest {
  size_t k_;
  priority_queue<int, vector<int>, greater<int>> top_k_;
public:
  KthLargest(int k, vector<int>& nums) {
      if (k <= 0) {
          throw std::invalid_argument("k must be positive");
      }

      k_ = static_cast<size_t>(k);
      for (int n: nums) {
          add(n);
      }
  }
  
  int add(int val) {
      top_k_.push(val);

      if (top_k_.size() > k_) {
          top_k_.pop();
      }

      return top_k_.top();
  }
};

/**
* Your KthLargest object will be instantiated and called as such:
* KthLargest* obj = new KthLargest(k, nums);
* int param_1 = obj->add(val);
*/