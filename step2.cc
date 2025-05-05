class KthLargest {
  int k_;
  priority_queue<int, vector<int>, greater<int>> top_k_;
public:
  KthLargest(int k, vector<int>& nums) : k_(k) {
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