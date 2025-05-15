class Solution {
public:
    string get_reduced_local_name(const string& local_name) {
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
            string local_name = get_reduced_local_name(email.substr(0, at_index));
            string domain_name = email.substr(at_index + 1);
            email_addresses.insert(local_name + '@' + domain_name);
        }
        return email_addresses.size();
    }
};
