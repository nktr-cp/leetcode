class Solution {
public:
    string GetCanonicalLocal(const string_view& local_name) {
        string canonical_local;

        for (const char c : local_name) {
            if (c == '.') {
                continue;
            }
            if (c == '+') {
                return canonical_local;
            }
            canonical_local.push_back(c);
        }

        return canonical_local;
    }

    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> canonical_emails;

        for (const auto& email : emails) {
            size_t at_index = email.find('@');
            string canonical_local = GetCanonicalLocal(string_view(email).substr(0, at_index));
            string_view domain = string_view(email).substr(at_index + 1);
            canonical_emails.insert(canonical_local + '@' + string(domain));
        }

        return canonical_emails.size();
    }
};
