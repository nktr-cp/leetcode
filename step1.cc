class KthLargest {
  private:
      int k_;
      std::priority_queue<int, std::vector<int>, std::greater<int>> top_k_;
  public:
      KthLargest(int k, vector<int>& nums) : k_(k) {
          for (int n: nums) {
              top_k_.push(n);
          }
  
          while (top_k_.size() > k) {
              top_k_.pop();
          }
      }
      
      int add(int val) {
          if (top_k_.size() < k_) {
              top_k_.push(val);
              return top_k_.top();
          }
          int current_k = top_k_.top();
  
          if (current_k > val) {
              return current_k;
          }
  
          top_k_.pop();
          top_k_.push(val);
  
          return top_k_.top();
      }
  };
  
  /**
   * Your KthLargest object will be instantiated and called as such:
   * KthLargest* obj = new KthLargest(k, nums);
   * int param_1 = obj->add(val);
   */