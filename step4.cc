class Solution {
  public:
      bool isValid(string s) {
          const std::unordered_map<char, char> open_to_close = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
  
          std::stack<char> unclosed_brackets;
          for (char c: s) {
              if (open_to_close.contains(c)) {
                  unclosed_brackets.push(c);
                  continue;
              }
  
              if (unclosed_brackets.empty() || open_to_close.at(unclosed_brackets.top()) != c) {
                  return false;
              }
              unclosed_brackets.pop();
          }
  
          return unclosed_brackets.empty();
      }
  };