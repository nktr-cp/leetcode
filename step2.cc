class KthLargest {
  int k_;
  std::priority_queue<int, std::vector<int>, std::greater<int>> top_k_;
public:
  KthLargest(int k, vector<int>& nums) : k_(k) {
      for (int n: nums) {
          top_k_.push(n);

          if (top_k_.size() > k) {
              top_k_.pop();
          }
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