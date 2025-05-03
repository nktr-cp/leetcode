class Solution {
  public:
      bool isValid(string s) {
          const std::string open_brackets = "({[";
          const std::string close_brackets = ")}]";
          const std::unordered_map<char,char> close_to_open = {{')','('}, {'}', '{'}, {']', '['}};
  
          std::stack<char> unclosed_brackets;
          for (const char& c: s) {
              if (open_brackets.contains(c)) {
                  unclosed_brackets.push(c);
                  continue;
              }
  
              if (!close_brackets.contains(c)) {
                  throw std::invalid_argument("Input string must consist only of '(){}[]'");
              }
  
              if (unclosed_brackets.empty()) {
                  return false;
              }
              
              if (unclosed_brackets.top() != close_to_open.at(c)) {
                  return false;
              }
              unclosed_brackets.pop();
          }
  
          return unclosed_brackets.empty();
      }
  };