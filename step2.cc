class Solution {
public:
    string get_canonical_local_name(const string_view& local_name) {
        string reduced_name;
        for (const char c : local_name) {
            if (c == '.') {
                continue;
            }
            if (c == '+') {
                return reduced_name;
            }
            reduced_name.push_back(c);
        }
        return reduced_name;
    }

    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> email_addresses;
        for (const string& email : emails) {
            size_t at_index = email.find('@');
            string canonical_local = get_canonical_local_name(string_view(email).substr(0, at_index));
            string_view domain = string_view(email).substr(at_index + 1);
            email_addresses.insert(canonical_local + '@' + string(domain));
        }
        return email_addresses.size();
    }
};
