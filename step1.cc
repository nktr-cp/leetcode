class Solution {
  public:
      bool isValid(string s) {
          std::stack<char> stk;
          const std::string open_brackets = "([{";
  
          for (const char& c: s) {
              if (open_brackets.find(c) != std::string::npos) {
                  stk.push(c);
                  continue;
              }
  
              if (stk.empty()) {
                  return false;
              }
  
              if (c == ')') {
                  if (stk.top() != '(') {
                      return false;
                  }
                  stk.pop();
              } else 
              if (c == '}') {
                  if (stk.top() != '{') {
                      return false;
                  }
                  stk.pop();
              }
              if (c == ']') {
                  if (stk.top() != '[') {
                      return false;
                  }
                  stk.pop();
              }
          }
  
          return stk.empty();
      }
  };